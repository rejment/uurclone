// Static helper class to read todays entries from the log file and fill a listbox
//
struct Today
{

	static char * getToken(char* &ptr, char *EOF)
	{
		char *start = ptr;
		for (;*ptr!='\t' && *ptr!='\n' && ptr<EOF; ptr++) if (*ptr=='\r') *ptr=0;

		if (ptr == EOF) return 0;
		*ptr++ = 0;
		return start;
	}

    static void Update(CListView &listview, CControl &total, LPCSTR log)
    {
        SetThreadLocale(MAKELCID(MAKELANGID(LANG_SWEDISH, SUBLANG_SWEDISH), SORT_DEFAULT));

        total.SetWindowTextA("Total:");
        listview.Clear();

		File f;
		if (!f.Read(log)) return;
		if (f.GetFileSize() == 0) return;

		char *logfile = f;
		char *EOF = (char*)f + f.GetFileSize();

		char buf[128];
		::GetDateFormat(LOCALE_USER_DEFAULT, 0, 0, "yyyy-MM-dd", buf, 128);

		char *date = 0;
        char *time = 0;
        char *activity = 0;
        char *comment = 0;
        char *duration = 0;

        float totalduration = 0.0f;
		while (true) {
			if (!(date = getToken(logfile, EOF))) break;
            if (!(time = getToken(logfile, EOF))) break;
            if (!(activity = getToken(logfile, EOF))) break;
            if (!(comment = getToken(logfile, EOF))) break;
            if (!(duration = getToken(logfile, EOF))) break;

            if (strncmp(date, buf, 10)==0) {
                *(comment-1) = '-';
                listview.InsertItem(time, activity, duration);
                totalduration += atof(duration);
            }
        }

        char totalstring[100];
        memcpy(totalstring, "Total: ", 7);
        strcpy(totalstring+7, Math::PrintFloat(totalduration));
        
        total.SetWindowTextA(totalstring);
    }
};