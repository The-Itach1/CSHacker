#pragma once
class Basefuntion
{
public:
    DWORD* P2(DWORD*, DWORD);//计算两级偏移
    DWORD* P3(DWORD*, DWORD, DWORD);//计算三级偏移
    DWORD* P4(DWORD*, DWORD, DWORD, DWORD);//计算四级偏移

    HANDLE GetProcessHandle();
    HANDLE GetOnePeHandle(LPCSTR lpName);

};


