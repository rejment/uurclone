#pragma once

class MRUList
{
public:
	char *	list[10];
	char	section[256];
	Properties &props;

	MRUList(Properties &_props, char* section) : props(_props)
	{
		char prop[6] = "item0";
		for (int i=0; i<10; i++)
		{
			list[i] = new char[256];
			prop[4] = '0' + i;
			props.GetString(section, prop, list[i], 256);
		}
		strncpy(this->section, section, 255);
	}

	~MRUList()
	{
		for (int i=0; i<10; i++)
		{
			delete [] list[i];
			list[i] = 0;
		}
	}

	void MakeCombo(CComboBox &combo)
	{
		combo.ResetContent();
		for (int i=0; i<10; i++)
			if (list[i][0] != 0)
				combo.AddString(list[i]);
		combo.SetCurSel(0);
	}

	void UpdateAndSave(CComboBox &combo)
	{
		char str[256];
		combo.GetWindowText(str, 256);
		Update(str);
		Save(props);
	}

	void Update(char *latest)
	{
		int foundat = 9;
		for (int i=0; i<10; i++)
		{
			if (strncmp(list[i], latest, 256) == 0)
			{
				foundat = i;
				break;
			}
		}

		// rotate by one (up to the one to move to front)
		char *oldest = list[foundat];
		for (int i=foundat-1; i>=0; --i)
			list[i+1] = list[i];
		list[0] = oldest;
		// update first one
		strncpy(list[0], latest, 256);
	}

	void Save(Properties &props)
	{
		char prop[6] = "item0";
		for (int i=0; i<10; i++)
		{
			prop[4] = '0' + i;
			props.SetString(section, prop, list[i]);
		}
	}

};