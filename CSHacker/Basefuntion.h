#pragma once
class Basefuntion
{
public:
    DWORD* P2(DWORD*, DWORD);//��������ƫ��
    DWORD* P3(DWORD*, DWORD, DWORD);//��������ƫ��
    DWORD* P4(DWORD*, DWORD, DWORD, DWORD);//�����ļ�ƫ��

    HANDLE GetProcessHandle();
    HANDLE GetOnePeHandle(LPCSTR lpName);

};


