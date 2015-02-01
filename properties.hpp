#pragma once

class Properties
{
public:
	char fname[MAX_PATH];

	Properties(char *file = NULL)
	{
		if (file == NULL)
		{
			int fs = ::GetModuleFileName(NULL, fname, MAX_PATH);
            //*((int*)(fname+fs-3)) = MAKEFOURCC('i','n','i',0);
			strcpy(fname+fs-3, "ini");
		}
		else
		{
			strncpy_s(fname, file, MAX_PATH);
		}
	}

	int GetString(char *section, char *property, char *returned, int maxsize, char *def = NULL)
	{
		char *d = "";
		if (def == NULL) def = d;
		return ::GetPrivateProfileString(section, property, def, returned, maxsize, fname);
	}
	int GetInt(char *section, char *property, int def = 0)
	{
		return ::GetPrivateProfileInt(section, property, def, fname);
	}
	void SetString(char *section, char *property, char *value)
	{
		::WritePrivateProfileString(section, property, value, fname);
	}
	void SetInt(char *section, char *property, int value)
	{
		char buf[40];
		SetString(section, property, itoa(value, buf, 10));
	}
};