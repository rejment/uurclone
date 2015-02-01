#pragma once

/*
 * Much smaller than WTL library. Some similarities. Many differences. No documentation.
 *  v0.2	Changed CDlgItem to CControl, added CComboBox
 *  v0.1	CDialog and CDlgItem are working, although w/o much functionality.
 */

#define BEGIN_MSG_MAP() \
public: \
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult) \
	{ \
		BOOL bHandled = TRUE; \
		(hWnd); \
		(uMsg); \
		(wParam); \
		(lParam); \
		(lResult); \
		(bHandled);

#define CHAIN_MSG_MAP_MEMBER(theChainMember) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}

#define MESSAGE_HANDLER(msg, func) \
	if(uMsg == msg) \
	{ \
		bHandled = TRUE; \
		lResult = func(uMsg, wParam, lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

#define COMMAND_ID_HANDLER(id, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}

#define END_MSG_MAP() \
		return FALSE; \
	}



template <class T>
class CDialog
{
public:

	HWND m_hWnd;

	HRESULT DoModal()
	{
		return (HRESULT) ::DialogBoxParam(::GetModuleHandle(NULL), MAKEINTRESOURCE(static_cast<T*>(this)->IDD), NULL, DialogProc, reinterpret_cast<LPARAM>(this));
	}

	HWND GetDlgItem(int nIDDlgItem)
	{
		return ::GetDlgItem(m_hWnd, nIDDlgItem);
	}

	BOOL EndDialog(int nResult)
	{
		return ::EndDialog(m_hWnd, nResult);
	}

	static INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		if (uMsg == WM_INITDIALOG)
		{
			::SetWindowLong(hwndDlg, GWL_USERDATA, (LONG) lParam);
		}

		LRESULT lResult = 0;
		T* pt = reinterpret_cast<T*> (::GetWindowLong(hwndDlg, GWL_USERDATA));
		if (pt != NULL)
		{
			pt->m_hWnd = hwndDlg;
			return pt->ProcessWindowMessage(hwndDlg, uMsg, wParam, lParam, lResult);
		}

		return FALSE;
	}
};

class CControl
{
public:
	HWND m_hWnd;

	void Attach(HWND hwnd)
	{
		this->m_hWnd = hwnd;
	}

	int GetWindowText(LPTSTR lpString, int nMaxCount)
	{
		return ::GetWindowText(m_hWnd, lpString, nMaxCount);
	}

	int SetWindowText(LPCSTR lpString)
	{
		return ::SetWindowText(m_hWnd, lpString);
	}

    LRESULT SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam)
    {
        return ::SendMessage(m_hWnd, Msg, wParam, lParam);
    }

};

class CComboBox : public CControl
{
public:
	int GetCount()
	{
		return (int) SendMessage(CB_GETCOUNT, 0, 0L);
	}

	int GetCurSel()
	{
		return (int) SendMessage(CB_GETCURSEL, 0, 0L);
	}

	int SetCurSel(int nSelect)
	{
		return (int) SendMessage(CB_SETCURSEL, nSelect, 0L);
	}

	void ResetContent()
	{
		SendMessage(CB_RESETCONTENT, 0, 0L);
	}

	int AddString(LPCTSTR lpszString)
	{
		return (int) SendMessage(CB_ADDSTRING, 0, (LPARAM)lpszString);
	}
	int DeleteString(UINT nIndex)
	{
		return (int) SendMessage(CB_DELETESTRING, nIndex, 0L);
	}

	int InsertString(int nIndex, LPCTSTR lpszString)
	{
		return (int) SendMessage(CB_INSERTSTRING, nIndex, (LPARAM)lpszString);
	}
};

class CListView : public CControl
{
public:
    BOOL SetColumn(int pos, LPSTR title, int width)
    {
        LVCOLUMN col = {0};
        col.mask = LVCF_TEXT | LVCF_WIDTH;
        col.pszText = title;
        col.cx = width;
        BOOL x = ListView_InsertColumn(m_hWnd, pos, &col);
        return x;
    }

    int InsertItem(LPSTR lpszTime, LPSTR lpszActivity, LPSTR lpszDuration)
    {
        LVITEM lvi = {0};
        lvi.mask = LVIF_TEXT;
        lvi.pszText = lpszTime;
        lvi.iItem = 99999;
        int pos = ListView_InsertItem(m_hWnd, &lvi);
        ListView_SetItemText(m_hWnd, pos, 1, lpszActivity);
        ListView_SetItemText(m_hWnd, pos, 2, lpszDuration);
        return pos;
    }

    BOOL Clear()
    {
        return ListView_DeleteAllItems(m_hWnd);
    }
};
