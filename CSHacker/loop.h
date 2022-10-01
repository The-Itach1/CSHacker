#pragma once

static HANDLE g_hExitBulletsEvent;
static HANDLE Bullets_Thread;

DWORD WINAPI Loop_SetBullets(LPVOID lpParam);

void SetBullets();
void OutBullets();



static HANDLE g_hExitHpEvent;
static HANDLE Hp_Thread;

DWORD WINAPI Loop_SetHp(LPVOID lpParam);

void SetHp();
void OutHp();

static HANDLE g_hExitArmorEvent;
static HANDLE Armor_Thread;

DWORD WINAPI Loop_SetArmor(LPVOID lpParam);

void SetArmor();
void OutArmor();


static HANDLE g_hExitShopEvent;
static HANDLE Shop_Thread;

DWORD WINAPI Loop_SetShop(LPVOID lpParam);


static HANDLE g_hExitShootEvent;
static HANDLE Shoot_Thread;

DWORD WINAPI Loop_SetShop(LPVOID lpParam);
void SetShoot();
void OutShoot();


void SetShop();
void OutShop();

BOOL SetStiff();
BOOL OutStiff();

BOOL SetWeapon();
BOOL OutWeapon();

BOOL SetView();
BOOL OutView();

BOOL SetMoney();



