#include "pch.h"
#include "loop.h"
#include "Basefuntion.h"
//血量修改

DWORD WINAPI Loop_SetBullets(LPVOID lpParam)
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD Bullets_offset1 = 0x11069BC;
	DWORD Bullets_offset2 = 0x7c;
	DWORD Bullets_offset3 = 0x5ec;
	DWORD Bullets_offset4 = 0xcc;


	hProcess=bf.GetProcessHandle();

	dwExeImageBase = (DWORD)GetModuleHandle(NULL);

	SIZE_T  dwSize = 0;
	DWORD BulletsNum1;
	DWORD BulletsNum2 = 30;
	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;
	DWORD addr3;
	DWORD addr4;


	while (1)
	{
		DWORD dwWaitCode = WaitForSingleObject(g_hExitBulletsEvent, 0);
		if (WAIT_OBJECT_0 == dwWaitCode)
		{
			break;
		}
		if (ReadProcessMemory(hProcess, (LPVOID)(Bullets_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
		{
			if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + Bullets_offset2), &addr2, sizeof(DWORD), &dwSize))
			{
				if (ReadProcessMemory(hProcess, (LPVOID)(addr2 + Bullets_offset3), &addr3, sizeof(DWORD), &dwSize))
				{
					BOOL ret = ReadProcessMemory(hProcess, (LPVOID)(addr3 + Bullets_offset4), &BulletsNum1, sizeof(DWORD), &dwSize);
					if (ret == 0)
					{
						continue;
					}
					else
					{
						if (20 > BulletsNum1)
							WriteProcessMemory(hProcess, (LPVOID)(addr3 + Bullets_offset4), &BulletsNum2, sizeof(DWORD), &dwSize);
						else
						{
							Sleep(1500);
						}
					}
				}
			}
		}
	}
	return 1;
}


void SetBullets()
{
	g_hExitBulletsEvent = CreateEvent(0, 0, 0, 0);
	Bullets_Thread=CreateThread(NULL, 0, Loop_SetBullets, NULL, 0, NULL);
}

void OutBullets()
{
	SetEvent(g_hExitBulletsEvent);
	Sleep(3000);
	DWORD dwWaitCode = WaitForSingleObject(Bullets_Thread, INFINITE);
	if (dwWaitCode == WAIT_OBJECT_0)
	{
		CloseHandle(Bullets_Thread);
	}
}


//锁血
DWORD WINAPI Loop_SetHp(LPVOID lpParam)
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD Hp_offset1 = 0x13A020;
	DWORD Hp_offset2 = 0x2EB0;
	DWORD Hp_offset3 = 0x160;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;
	float HpNum1;
	float HpNum2 = 200;
	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;
	DWORD addr3;
	DWORD addr4;


	while (1)
	{
		DWORD dwWaitCode = WaitForSingleObject(g_hExitHpEvent, 0);
		if (WAIT_OBJECT_0 == dwWaitCode)
		{
			break;
		}
		if (ReadProcessMemory(hProcess, (LPVOID)(Hp_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
		{
			if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + Hp_offset2), &addr2, sizeof(DWORD), &dwSize))
			{
				BOOL ret = ReadProcessMemory(hProcess, (LPVOID)(addr2 + Hp_offset3), &HpNum1, sizeof(float), &dwSize);
				if (ret == 0)
				{
					continue;
				}
				else
				{
					if ((float)170 > HpNum1)
						WriteProcessMemory(hProcess, (LPVOID)(addr2 + Hp_offset3), &HpNum2, sizeof(float), &dwSize);
					else
					{
						Sleep(10);
					}
				}
				
			}
		}
	}
	return 1;
}


void SetHp()
{
	g_hExitHpEvent = CreateEvent(0, 0, 0, 0);
	Hp_Thread = CreateThread(NULL, 0, Loop_SetHp, NULL, 0, NULL);
}

void OutHp()
{
	SetEvent(g_hExitHpEvent);
	Sleep(3000);
	DWORD dwWaitCode = WaitForSingleObject(Hp_Thread, INFINITE);
	if (dwWaitCode == WAIT_OBJECT_0)
	{
		CloseHandle(Hp_Thread);
	}
}


//锁甲
DWORD WINAPI Loop_SetArmor(LPVOID lpParam)
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD Armor_offset1 = 0x13A020;
	DWORD Armor_offset2 = 0x2EB0;
	DWORD Armor_offset3 = 0x1bc;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;
	float ArmorNum1;
	float ArmorNum2 = 200;


	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;
	DWORD addr3;
	DWORD addr4;


	while (1)
	{
		DWORD dwWaitCode = WaitForSingleObject(g_hExitArmorEvent, 0);
		if (WAIT_OBJECT_0 == dwWaitCode)
		{
			break;
		}
		if (ReadProcessMemory(hProcess, (LPVOID)(Armor_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
		{
			if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + Armor_offset2), &addr2, sizeof(DWORD), &dwSize))
			{
				BOOL ret = ReadProcessMemory(hProcess, (LPVOID)(addr2 + Armor_offset3), &ArmorNum1, sizeof(float), &dwSize);
				if (ret == 0)
				{
					continue;
				}
				else
				{
					if ((float)170 > ArmorNum1)
						WriteProcessMemory(hProcess, (LPVOID)(addr2 + Armor_offset3), &ArmorNum2, sizeof(float), &dwSize);
					else
					{
						Sleep(10);
					}
				}

			}
		}
	}
	return 1;
}


void SetArmor()
{
	g_hExitArmorEvent = CreateEvent(0, 0, 0, 0);
	Armor_Thread = CreateThread(NULL, 0, Loop_SetArmor, NULL, 0, NULL);
}

void OutArmor()
{
	SetEvent(g_hExitArmorEvent);
	Sleep(3000);
	DWORD dwWaitCode = WaitForSingleObject(Armor_Thread, INFINITE);
	if (dwWaitCode == WAIT_OBJECT_0)
	{
		CloseHandle(Armor_Thread);
	}
}

//随地购物
DWORD WINAPI Loop_SetShop(LPVOID lpParam)
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD Shop_offset1 = 0x11069BC;
	DWORD Shop_offset2 = 0x7c;
	DWORD Shop_offset3 = 0x3c0;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase =(DWORD) GetModuleHandle(NULL);

	SIZE_T  dwSize = 0;
	DWORD IsOnShop=0;
	DWORD OnShop = 1;
	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;
	DWORD addr3;
	DWORD addr4;


	while (1)
	{
		DWORD dwWaitCode = WaitForSingleObject(g_hExitShopEvent, 0);
		if (WAIT_OBJECT_0 == dwWaitCode)
		{
			break;
		}
		if (ReadProcessMemory(hProcess, (LPVOID)(Shop_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
		{
			if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + Shop_offset2), &addr2, sizeof(DWORD), &dwSize))
			{
				BOOL ret = ReadProcessMemory(hProcess, (LPVOID)(addr2 + Shop_offset3), &IsOnShop, sizeof(DWORD), &dwSize);
				if (ret == 0)
				{
					continue;
				}
				else
				{
					if (IsOnShop==0)
						WriteProcessMemory(hProcess, (LPVOID)(addr2 + Shop_offset3), &OnShop, sizeof(DWORD), &dwSize);
					else
					{
						Sleep(10);
					}
				}

			}
		}
	}
	return 1;
}


void SetShop()
{
	g_hExitShopEvent = CreateEvent(0, 0, 0, 0);
	Shop_Thread = CreateThread(NULL, 0, Loop_SetShop, NULL, 0, NULL);
}

void OutShop()
{
	SetEvent(g_hExitShopEvent);
	Sleep(3000);
	DWORD dwWaitCode = WaitForSingleObject(Shop_Thread, INFINITE);
	if (dwWaitCode == WAIT_OBJECT_0)
	{
		CloseHandle(Shop_Thread);
	}
}


BOOL SetStiff()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD oldProtect = NULL;//老的内存权限

	DWORD dwExeImageBase;
	DWORD Code_offset1 = 0x8FBCE;
	DWORD Code_offset2 = 0x8FB7B;
	DWORD Stiff_Num = 0x3F800000;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;


	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}


	/*
		先改变他的读写权限
		VirtualProtectEx
		GetCurrentProcess 获取当前进程的句柄 因为是DLL注入到游戏里  这里也就是游戏的句柄
		PAGE_EXECUTE 可读写
	*/

	//无甲时
	if (VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase+ Code_offset1), 4, PAGE_EXECUTE_READWRITE, &oldProtect))
	{//读写权限更改成功后
		//需要写入的字节数
		WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Code_offset1), &Stiff_Num, sizeof(DWORD), &dwSize);
	}
	else
	{
		MessageBoxW(0, L"wirte error", L"wirte error", MB_OK);
	}

	VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset1), 4, oldProtect, &oldProtect);//恢复之前的读写权限


	//有甲时
	if (VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset2), 4, PAGE_EXECUTE_READWRITE, &oldProtect))
	{//读写权限更改成功后
		//需要写入的字节数
		WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Code_offset2), &Stiff_Num, sizeof(DWORD), &dwSize);
	}
	else
	{
		MessageBoxW(0, L"wirte error", L"wirte error", MB_OK);
	}

	VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset2), 4, oldProtect, &oldProtect);//恢复之前的读写权限

	return 0;
}

BOOL OutStiff()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD oldProtect = NULL;//老的内存权限

	DWORD dwExeImageBase;
	DWORD Code_offset1 = 0x8FBCE;
	DWORD Code_offset2 = 0x8FB7B;
	DWORD Stiff_Num1 = 0x3F000000;
	DWORD Stiff_Num2 = 0x3F266666;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;

	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}


	/*
		先改变他的读写权限
		VirtualProtectEx
		GetCurrentProcess 获取当前进程的句柄 因为是DLL注入到游戏里  这里也就是游戏的句柄
		PAGE_EXECUTE 可读写
	*/

	//无甲时
	if (VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset1), 4, PAGE_EXECUTE_READWRITE, &oldProtect))
	{//读写权限更改成功后
		//需要写入的字节数
		WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Code_offset1), &Stiff_Num1, sizeof(DWORD), &dwSize);
	}
	else
	{
		MessageBoxW(0, L"wirte error", L"wirte error", MB_OK);
	}

	VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset1), 4, oldProtect, &oldProtect);//恢复之前的读写权限


	//有甲时
	if (VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset2), 4, PAGE_EXECUTE_READWRITE, &oldProtect))
	{//读写权限更改成功后
		//需要写入的字节数
		WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Code_offset2), &Stiff_Num2, sizeof(DWORD), &dwSize);
	}
	else
	{
		MessageBoxW(0, L"wirte error", L"wirte error", MB_OK);
	}

	VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Code_offset2), 4, oldProtect, &oldProtect);//恢复之前的读写权限

	return 0;
}

BOOL SetMoney()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD Money_offset1 = 0x11069BC;
	DWORD Money_offset2 = 0x7c;
	DWORD Money_offset3 = 0x1cc;
	DWORD Show_Money_offset1 = 0x61B9FC;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)GetModuleHandle(NULL);

	SIZE_T  dwSize = 0;
	DWORD NowMoney;
	DWORD ShowMoney;
	DWORD SetMoney = 16000;
	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;


	//这个是实际的金钱值，但是想要购买，还需要修改显示的金钱值，不然购买武器为灰色。
	if (ReadProcessMemory(hProcess, (LPVOID)(Money_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
	{
		if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + Money_offset2), &addr2, sizeof(DWORD), &dwSize))
		{
			if (ReadProcessMemory(hProcess, (LPVOID)(addr2 + Money_offset3), &NowMoney, sizeof(DWORD), &dwSize))
			{
				//修改显示的金钱值
				if (ReadProcessMemory(hProcess, (LPVOID)(dwExeImageBase+ Show_Money_offset1), &ShowMoney, sizeof(DWORD), &dwSize))
				{
					WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Show_Money_offset1), &SetMoney, sizeof(DWORD), &dwSize);
					WriteProcessMemory(hProcess, (LPVOID)(addr2 + Money_offset3), &SetMoney, sizeof(DWORD), &dwSize);
				}
				
			}
		}
	}

	return 1;
}


DWORD WINAPI Loop_SetShoot(LPVOID lpParam)
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD Shoot_offset1 = 0x61B82C;
	DWORD IsEnemy;
	SIZE_T  dwSize = 0;

	hProcess = bf.GetProcessHandle();
	dwExeImageBase = (DWORD)GetModuleHandle(NULL);

	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	while (1)
	{
		DWORD dwWaitCode = WaitForSingleObject(g_hExitShootEvent, 0);
		if (WAIT_OBJECT_0 == dwWaitCode)
		{
			break;
		}

		if (ReadProcessMemory(hProcess, (LPVOID)(Shoot_offset1 + dwExeImageBase), &IsEnemy, sizeof(DWORD), &dwSize))
		{
			if (IsEnemy == 2)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(3);
			}
			else
			{
				Sleep(1);
			}

		}
	}

}

void SetShoot()
{
	g_hExitShootEvent = CreateEvent(0, 0, 0, 0);
	Shoot_Thread = CreateThread(NULL, 0, Loop_SetShoot, NULL, 0, NULL);
}

void OutShoot()
{
	SetEvent(g_hExitShootEvent);
	Sleep(3000);
	DWORD dwWaitCode = WaitForSingleObject(Shoot_Thread, INFINITE);
	if (dwWaitCode == WAIT_OBJECT_0)
	{
		CloseHandle(Shoot_Thread);
	}
}



BOOL SetWeapon()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD oldProtect = NULL;//老的内存权限

	DWORD dwExeImageBase;
	//DWORD Ak_offset = 0x1476;
	//DWORD Ak_offset = 0x9CB6;
	BYTE IncCode = 0x45;
	BYTE NopCode = 0x90;
	DWORD Weapon_Num = 2;
	DWORD Weapon_Array[5] = { 0x1476,0x9CB6 };
	int i;

	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;


	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}


	/*
		先改变他的读写权限
		VirtualProtectEx
		GetCurrentProcess 获取当前进程的句柄 因为是DLL注入到游戏里  这里也就是游戏的句柄
		PAGE_EXECUTE 可读写
	*/
	for (i = 0; i < Weapon_Num; i++)
	{
		if (VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Weapon_Array[i]), 1, PAGE_EXECUTE_READWRITE, &oldProtect))
		{//读写权限更改成功后
			//需要写入的字节数
			WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Weapon_Array[i]), &NopCode, sizeof(BYTE), &dwSize);
		}
		else
		{
			MessageBoxW(0, L"wirte error", L"wirte error", MB_OK);
		}

		VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Weapon_Array[i]), 1, oldProtect, &oldProtect);//恢复之前的读写权限

	}
	
	return 1;
}

BOOL OutWeapon()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD oldProtect = NULL;//老的内存权限

	DWORD dwExeImageBase;
	//DWORD Ak_offset = 0x1476;
	//DWORD Ak_offset = 0x9CB6;
	BYTE IncCode = 0x45;
	BYTE NopCode = 0x90;
	DWORD Weapon_Num = 2;
	DWORD Weapon_Array[5] = { 0x1476,0x9CB6 };
	int i;

	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;


	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}


	/*
		先改变他的读写权限
		VirtualProtectEx
		GetCurrentProcess 获取当前进程的句柄 因为是DLL注入到游戏里  这里也就是游戏的句柄
		PAGE_EXECUTE 可读写
	*/
	for (i = 0; i < Weapon_Num; i++)
	{
		if (VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Weapon_Array[i]), 1, PAGE_EXECUTE_READWRITE, &oldProtect))
		{//读写权限更改成功后
			//需要写入的字节数
			WriteProcessMemory(hProcess, (LPVOID)(dwExeImageBase + Weapon_Array[i]), &IncCode, sizeof(BYTE), &dwSize);
		}
		else
		{
			MessageBoxW(0, L"wirte error", L"wirte error", MB_OK);
		}

		VirtualProtectEx(hProcess, (LPVOID)(dwExeImageBase + Weapon_Array[i]), 1, oldProtect, &oldProtect);//恢复之前的读写权限

	}

	return 1;
}
BOOL SetView()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD View_offset1 = 0x13A020;
	DWORD View_offset2 = 0x2EB0;
	DWORD View_offset3 = 0x244;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;
	DWORD View_Normal= 0;
	DWORD View_Free = 3;

	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;


	if (ReadProcessMemory(hProcess, (LPVOID)(View_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
	{
		if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + View_offset2), &addr2, sizeof(DWORD), &dwSize))
		{
			BOOL ret = ReadProcessMemory(hProcess, (LPVOID)(addr2 + View_offset3), &View_Normal, sizeof(DWORD), &dwSize);
			if (ret != 0 && View_Normal==0)
			{
				WriteProcessMemory(hProcess, (LPVOID)(addr2 + View_offset3), &View_Free, sizeof(DWORD), &dwSize);
			}
			else
			{
				return 0;

			}

		}
	}

	return 1;
}


BOOL OutView()
{
	Basefuntion bf;
	HANDLE hProcess = NULL;
	DWORD dwExeImageBase;
	DWORD View_offset1 = 0x13A020;
	DWORD View_offset2 = 0x2EB0;
	DWORD View_offset3 = 0x244;


	hProcess = bf.GetProcessHandle();

	dwExeImageBase = (DWORD)bf.GetOnePeHandle("mp.dll");

	SIZE_T  dwSize = 0;
	DWORD View_Normal = 0;
	DWORD View_Free;

	if (hProcess == NULL)
	{
		MessageBoxW(0, L"Open process error", L"Open process error", MB_OK);
		return 0;
	}

	if (dwExeImageBase == NULL)
	{
		MessageBoxW(0, L"Get ExeBase error", L"Get ExeBase error", MB_OK);
		return 0;
	}

	DWORD addr1;
	DWORD addr2;


	if (ReadProcessMemory(hProcess, (LPVOID)(View_offset1 + dwExeImageBase), &addr1, sizeof(DWORD), &dwSize))
	{
		if (ReadProcessMemory(hProcess, (LPVOID)(addr1 + View_offset2), &addr2, sizeof(DWORD), &dwSize))
		{
			BOOL ret = ReadProcessMemory(hProcess, (LPVOID)(addr2 + View_offset3), &View_Free, sizeof(DWORD), &dwSize);
			if (ret != 0 && View_Free == 3)
			{
				WriteProcessMemory(hProcess, (LPVOID)(addr2 + View_offset3), &View_Normal, sizeof(DWORD), &dwSize);
			}
			else
			{
				return 0;

			}

		}
	}

	return 1;
}