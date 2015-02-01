#pragma once

#define TASKBAR_MESSAGE_HANDLER(ti, msg, func) \
	if(uMsg==ti.m_nid.uCallbackMessage && wParam==ti.m_nid.uID && lParam==msg) \
   { \
   bHandled = TRUE; \
   lResult = func(lParam, bHandled); \
   if(bHandled) \
   return TRUE; \
   }

class CTrayIcon
{
public:
	NOTIFYICONDATA m_nid; 
	HMENU m_hMenu;
	UINT m_iTaskbarRestartMsg;

	CTrayIcon() : m_hMenu(NULL)
	{
		::RtlSecureZeroMemory(&m_nid, sizeof(m_nid));
		m_nid.cbSize = sizeof(m_nid); 
		m_nid.uCallbackMessage = ::RegisterWindowMessage(TEXT("TrayIconNotifyMsg"));
		m_iTaskbarRestartMsg = ::RegisterWindowMessage(TEXT("TrayIconCreated"));
	}

	~CTrayIcon()
	{
		Uninstall();
	}

	BEGIN_MSG_MAP()
		MESSAGE_HANDLER(m_iTaskbarRestartMsg, OnTaskbarRestart)
		TASKBAR_MESSAGE_HANDLER((*this), WM_RBUTTONDOWN, OnTaskbarContextMenu)
	END_MSG_MAP()

	BOOL Install(HWND hWnd, UINT iID, UINT nRes, LPCSTR toolTip)
	{
		m_nid.hWnd = hWnd;
		m_nid.uID = iID;
		m_nid.hIcon = (HICON)::LoadImage(::GetModuleHandle(NULL), MAKEINTRESOURCE(nRes), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
		m_nid.szTip[0] = '\0';
		strcpy(m_nid.szTip, toolTip);
		m_hMenu = ::LoadMenu(::GetModuleHandle(NULL), MAKEINTRESOURCE(nRes));
		return AddTaskBarIcon();
	}
	BOOL Uninstall()
	{
		BOOL res = TRUE;
		if( m_nid.hWnd != NULL ) res = DeleteTaskBarIcon();
		m_nid.hWnd = NULL;
		if( m_nid.hIcon != NULL ) ::DestroyIcon(m_nid.hIcon);
		m_nid.hIcon = NULL;
		if( m_hMenu != NULL ) ::DestroyMenu(m_hMenu);
		m_hMenu = NULL;
		return res;
	}

	BOOL IsInstalled() const
	{
		return m_nid.hWnd!=NULL;
	}

	void SetIcon(HICON hIcon) 
	{ 
		m_nid.hIcon = hIcon; 
	}

	void SetMenu(HMENU hMenu) 
	{ 
		m_hMenu = hMenu; 
	}

	BOOL AddTaskBarIcon()
	{
		m_nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; 
		BOOL res = ::Shell_NotifyIcon(NIM_ADD, &m_nid); 
		return res;
	}
	BOOL ChangeIcon(HICON hIcon)
	{
		// NOTE: The class takes ownership of the icon!
		if( m_nid.hIcon != NULL ) ::DestroyIcon(m_nid.hIcon);
		m_nid.uFlags = NIF_ICON; 
		m_nid.hIcon = hIcon;
		BOOL res = ::Shell_NotifyIcon(NIM_MODIFY, &m_nid); 
		return res;
	}

	BOOL DeleteTaskBarIcon() 
	{ 
		return ::Shell_NotifyIcon(NIM_DELETE, &m_nid); 
	} 

	// Message handlers

	LRESULT OnTaskbarRestart(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		AddTaskBarIcon();
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnTaskbarContextMenu(LPARAM /*uMsg*/, BOOL& bHandled)
	{
		if( !::IsMenu(m_hMenu) ) {
			bHandled = FALSE;
			return 0;
		}
		HMENU hSubMenu = ::GetSubMenu(m_hMenu, 0);   
		// Make first menu-item the default (bold font)
		//::SetMenuDefaultItem(hSubMenu, 0, TRUE); 
		// Display the menu at the current mouse location.
        POINT pt = {0};
		::GetCursorPos(&pt);      
		::SetForegroundWindow(m_nid.hWnd);       // Fixes Win95 bug; see Q135788
		::TrackPopupMenu(hSubMenu, 0, pt.x, pt.y, 0, m_nid.hWnd, NULL);
		::PostMessage(m_nid.hWnd, WM_NULL, 0,0); // Fixes another Win95 bug
		return 0;
	}
};