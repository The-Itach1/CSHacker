#include "pch.h"
#include "Basefuntion.h"

DWORD* Basefuntion::P2(DWORD* p, DWORD offset)
{
	return (DWORD*)(*p + offset);;
}

DWORD* Basefuntion::P3(DWORD* p, DWORD offset, DWORD offset1)
{
	return (DWORD*)(*(DWORD*)(*p + offset) + offset1);
}

DWORD* Basefuntion::P4(DWORD* p, DWORD offset, DWORD offset1, DWORD offset2)
{
	return (DWORD*)(*(DWORD*)(*(DWORD*)(*p + offset) + offset1) + offset2);
}


HANDLE Basefuntion::GetProcessHandle()
{
    DWORD dwPid = 0;

    HWND hWnd = FindWindowW(NULL, L"Counter-Strike");
    if (hWnd == NULL) {
        MessageBox(0, "get hwnd error","get hwnd error",MB_OK);
    }
    GetWindowThreadProcessId(hWnd, &dwPid);
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
}




HANDLE Basefuntion::GetOnePeHandle(LPCSTR lpName)
{

    HANDLE handle = GetModuleHandleA(lpName);

    return handle;
}


