#pragma once

class LogFile
{
	static void Write(HANDLE file, char *str, BOOL tab)
	{
		DWORD written;
		::WriteFile(file, str, (DWORD) strlen(str), &written, 0);
		if (tab)
			::WriteFile(file, "\t", 1, &written, 0);
	}
public:

	static void Write(char*fname, char *str1, char *str2, char *str3)
	{

		HANDLE file = ::CreateFile(fname, GENERIC_WRITE, FILE_SHARE_READ, 0, OPEN_ALWAYS, 0,0);
		if (INVALID_HANDLE_VALUE != file)
		{
			::SetFilePointer(file, 0, 0, FILE_END);

			char buf[128];
			::GetDateFormat(LOCALE_USER_DEFAULT, 0, 0, "yyyy-MM-dd", buf, 128);
			Write(file, buf, true);
			::GetTimeFormat(LOCALE_USER_DEFAULT, 0, 0, "HH:mm", buf, 128);
			Write(file, buf, true);
			Write(file, str1, true);
			Write(file, str2, true);
			Write(file, str3, false);
			Write(file, "\r\n", false);

			::CloseHandle(file);
		}
	}
};