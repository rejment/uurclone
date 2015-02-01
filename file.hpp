#pragma once

// file.hpp - win32 file class (include <windows.h>)
// 
//	v1.2	Reallocation implemented.
//	v1.1	handle failures, operator char*()
//	v1.0	working version, little error handling

struct File
{
	File()
	{
		Data = 0;
		Free();
	}


	DWORD GetFileSize()
	{
		return this->FileSize;
	}

	bool SetFileSize(DWORD NewFileSize)
	{
		if (NewFileSize == FileSize)
			return true;

		// release any allocated memory
		if (NewFileSize == 0)
		{
			Free();
			return true;
		}

		// allocate new memory
		if (FileSize == 0) {
			Data = ::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, NewFileSize);
			if (Data)
			{
				this->FileSize = NewFileSize;
				return true;
			}
			return false;
		}

		// Reallocate memory to match the new requirements
		LPVOID NewData = ::HeapReAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, Data, NewFileSize);
		if (NewData)
		{
			this->FileSize = NewFileSize;
			this->Data = NewData;
			return true;
		}

		return false;
	}

	bool Write(LPCTSTR fname)
	{
		if (FileSize == 0)
			return false;
		HANDLE file = ::CreateFile(fname, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);
		if (file != INVALID_HANDLE_VALUE)
		{
			DWORD written = 0;
			::WriteFile(file, Data, FileSize, &written, 0);
			::CloseHandle(file);
		}
		return false;
	}

	bool Read(LPCTSTR fname)
	{
		//Free();
		HANDLE file = ::CreateFile(fname, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
		if (file != INVALID_HANDLE_VALUE)
		{
			DWORD fSize = ::GetFileSize(file, 0);
			if (this->SetFileSize(fSize))
			{
				DWORD read;
				::ReadFile(file, Data, fSize, &read, 0);
				::CloseHandle(file);
				if (read == fSize)
					return true;
				else
					Free();
			}
			else
			{
				::CloseHandle(file);
			}
		}

		return false;
	}

	void Free()
	{
		if (Data) ::HeapFree(::GetProcessHeap(), 0, Data);
		Data = 0;
		FileSize = 0;
	}

	inline operator char*()
	{
		return (char*) Data;
	}

	~File()
	{
		Free();
	}

	LPVOID	Data;
private:
	DWORD	FileSize;
};