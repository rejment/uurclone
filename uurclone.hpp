#pragma once

/*
 * Implementation of the UUR clone using my own tiny version of wtl.
 *
 * v 1.3 - ....
 * v 1.2 - 24 hour clock. Experimental excel export.
 * v 1.1 - Implemented Tomas Johansson's suggestions.
 *         Added duration. Everything combos. No custom format.
 * v 1.0 - Somewhat working version.
 */
class UURClone : public CDialog<UURClone>
{
public:
	enum { IDD = IDD_DIALOG1 };

	CComboBox activity;
	CComboBox comment;
	CComboBox duration;

	Properties props;
	CTrayIcon trayIcon;

    CListView todayLog;
    CControl todayLabel;


	int minutes;
	char logfile[MAX_PATH];

	BEGIN_MSG_MAP()
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnOk)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		COMMAND_ID_HANDLER(IDSTOP, OnExit)
		COMMAND_ID_HANDLER(IDEXPORT, OnExport)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
		CHAIN_MSG_MAP_MEMBER(trayIcon)
		TASKBAR_MESSAGE_HANDLER(trayIcon, WM_LBUTTONDOWN, OnShow)
	END_MSG_MAP()

	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL& b)
	{
		trayIcon.Install(m_hWnd, 1001, IDI_ICON1, "UUR");
		activity.Attach(GetDlgItem(IDC_COMBO1));
		comment.Attach(GetDlgItem(IDC_COMBO2));
		duration.Attach(GetDlgItem(IDC_COMBO3));
        todayLog.Attach(GetDlgItem(IDC_LIST1));
        todayLabel.Attach(GetDlgItem(IDC_TODAY_TOTAL));

		// read/write properties
		minutes = props.GetInt("UUR", "Minutes", 30);
		props.SetInt("UUR", "Minutes", minutes);
		props.GetString("UUR", "LogFile", logfile, MAX_PATH);
		if (logfile[0] == 0)
		{
			int fs = ::GetModuleFileName(NULL, logfile, MAX_PATH);
			strcpy(logfile+fs-3, "log");
		}
		props.SetString("UUR", "LogFile", logfile);

        todayLog.SetColumn(0, "Time", 40);
        todayLog.SetColumn(1, "Activity", 190);
        todayLog.SetColumn(2, "Duration", 60);

		return OnShow(0, b);
	}

	LRESULT OnOk(WORD, WORD wID, HWND, BOOL& h)
	{
		// update mru lists
		MRUList activityMru(props, "Activity");
		activityMru.UpdateAndSave(activity);

		MRUList commentMru(props, "Comment");
		commentMru.UpdateAndSave(comment);

		MRUList durationMru(props, "Duration");
		durationMru.UpdateAndSave(duration);

		// Do the logging
		LogFile::Write(logfile, activityMru.list[0], commentMru.list[0], durationMru.list[0]);

        return OnCancel(0,0,0,h);
	}

	LRESULT OnCancel(WORD, WORD wID, HWND, BOOL&)
	{
		ShowWindow(m_hWnd, SW_HIDE);
		SetTimer(m_hWnd, 1, 1000*60*minutes, 0);
		return TRUE;
	}

	LRESULT OnExit(WORD, WORD wID, HWND, BOOL&)
	{
		EndDialog(wID);
		return TRUE;
	}

	LRESULT OnExport(WORD, WORD wID, HWND, BOOL&)
	{
		char xml[MAX_PATH];
		int fs = ::GetModuleFileName(NULL, xml, MAX_PATH);
		strcpy(xml+fs-3, "xml");
        ExcelExport::Export(xml, logfile);
		::ShellExecute(0,"open",xml,0,0,0);
		return TRUE;
	}

	LRESULT OnTimer(UINT, WPARAM, LPARAM, BOOL& b)
	{
		KillTimer(m_hWnd, 1);
		return OnShow(0,b);
	}

	LRESULT OnShow(LPARAM, BOOL&)
	{
		MRUList activityMru(props, "Activity");
		activityMru.MakeCombo(activity);
		
		MRUList commentMru(props, "Comment");
		commentMru.MakeCombo(comment);

		MRUList durationMru(props, "Duration");
		durationMru.MakeCombo(duration);

		// lictiny.lib seems to whack floating point. 
		// don't care to investigate right now. this should do.
		char hrs[32];
		int trunc = minutes/60;
		int fract = (100*minutes)/60 - (100*trunc);
		itoa(trunc, hrs, 10);
		strcat(hrs, ",");
		if (fract<10) strcat(hrs, "0");
		itoa(fract, hrs+strlen(hrs), 10);
		duration.SetWindowText(hrs);


        // update todays log and total
        Today::Update(todayLog, todayLabel, logfile);


		::SetFocus(activity.m_hWnd);

		ShowWindow(m_hWnd, SW_NORMAL);
		::SetForegroundWindow(m_hWnd);
		return 0;
	}
};