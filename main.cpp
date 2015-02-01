#include <windows.h>
#include <commctrl.h>
#include <locale.h>
#include "resource.h"

#include "math.hpp"
#include "dwtl.hpp"
#include "trayicon.hpp"
#include "properties.hpp"
#include "mru.hpp"
#include "logfile.hpp"
#include "file.hpp"
#include "export.hpp"
#include "today.hpp"
#include "uurclone.hpp"

int __stdcall WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	UURClone uurc;

	HANDLE mtx = ::CreateMutex(NULL, TRUE, "UUR Mutex");
	if (mtx != NULL && ::GetLastError()!=ERROR_ALREADY_EXISTS)
	{
        INITCOMMONCONTROLSEX x;
        x.dwSize = sizeof(INITCOMMONCONTROLSEX);
        x.dwICC = ICC_LISTVIEW_CLASSES;
        ::InitCommonControlsEx(&x);

        return uurc.DoModal();
	}
	else
	{
		::MessageBox(NULL, "Only one instance at a time please!", "Error while starting UUR", MB_OK | MB_ICONERROR);
	}
	return 1;
}