// HackDialog.cpp: 实现文件
//

#include "pch.h"
#include "CSHacker.h"
#include "HackDialog.h"
#include "afxdialogex.h"
#include "Basefuntion.h"
#include "loop.h"


// HackDialog 对话框

IMPLEMENT_DYNAMIC(HackDialog, CDialog)

HackDialog::HackDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_Bullets(FALSE)
	, m_HP(FALSE)
	, m_Shop(FALSE)
	, m_Stiff(FALSE)
	, m_Shoot(FALSE)
	, m_Armor(FALSE)
	, m_Weapon(FALSE)
	, m_View(FALSE)
{

}

HackDialog::~HackDialog()
{
}

void HackDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Bullets_RADIO1, m_Bullets);
	DDX_Radio(pDX, IDC_HP_RADIO1, m_HP);
	DDX_Radio(pDX, IDC_Shop_RADIO1, m_Shop);
	DDX_Radio(pDX, IDC_Stiff_RADIO1, m_Stiff);
	DDX_Control(pDX, IDC_Money_BUTTON, m_Money);
	DDX_Radio(pDX, IDC_Shoot_RADIO1, m_Shoot);
	DDX_Radio(pDX, IDC_Armor_RADIO1, m_Armor);
	DDX_Radio(pDX, IDC_Weapon_RADIO1, m_Weapon);
	DDX_Radio(pDX, IDC_View_RADIO1, m_View);
}


BEGIN_MESSAGE_MAP(HackDialog, CDialog)

	ON_BN_CLICKED(IDC_Bullets_RADIO1, &HackDialog::OnBnClickedGroup1Radio)
	ON_BN_CLICKED(IDC_Bullets_RADIO2, &HackDialog::OnBnClickedGroup1Radio)
	ON_BN_CLICKED(IDC_HP_RADIO1, &HackDialog::OnBnClickedGroup2Radio)
	ON_BN_CLICKED(IDC_HP_RADIO2, &HackDialog::OnBnClickedGroup2Radio)
	ON_BN_CLICKED(IDC_Shop_RADIO1, &HackDialog::OnBnClickedGroup3Radio)
	ON_BN_CLICKED(IDC_Shop_RADIO2, &HackDialog::OnBnClickedGroup3Radio)
	ON_BN_CLICKED(IDC_Stiff_RADIO1, &HackDialog::OnBnClickedGroup4Radio)
	ON_BN_CLICKED(IDC_Stiff_RADIO2, &HackDialog::OnBnClickedGroup4Radio)
	ON_BN_CLICKED(IDC_Shoot_RADIO1, &HackDialog::OnBnClickedGroup5Radio)
	ON_BN_CLICKED(IDC_Shoot_RADIO2, &HackDialog::OnBnClickedGroup5Radio)
	ON_BN_CLICKED(IDC_Armor_RADIO1, &HackDialog::OnBnClickedGroup6Radio)
	ON_BN_CLICKED(IDC_Armor_RADIO2, &HackDialog::OnBnClickedGroup6Radio)
	ON_BN_CLICKED(IDC_Weapon_RADIO1, &HackDialog::OnBnClickedGroup7Radio)
	ON_BN_CLICKED(IDC_Weapon_RADIO2, &HackDialog::OnBnClickedGroup7Radio)
	ON_BN_CLICKED(IDC_View_RADIO1, &HackDialog::OnBnClickedGroup8Radio)
	ON_BN_CLICKED(IDC_View_RADIO2, &HackDialog::OnBnClickedGroup8Radio)

	ON_BN_CLICKED(IDC_Money_BUTTON, &HackDialog::OnBnClickedMoneyButton)
END_MESSAGE_MAP()


// HackDialog 消息处理程序


BOOL HackDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

INT_PTR HackDialog::DoModal()
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialog::DoModal();
}

void HackDialog::OnBnClickedGroup1Radio()
{
	DWORD dwWaitCode=NULL;

	UpdateData(true);
	switch (m_Bullets)
	{
	case 0:
		OutBullets();
		break;
	case 1:
		SetBullets();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedGroup2Radio()
{
	UpdateData(true);
	switch (m_HP)
	{
	case 0:
		OutHp();
		break;
	case 1:
		SetHp();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedGroup3Radio()
{
	UpdateData(true);
	switch (m_Shop)
	{
	case 0:
		OutShop();
		break;
	case 1:
		SetShop();
		break;
	default:
		break;
	}

}


void HackDialog::OnBnClickedGroup4Radio()
{
	
	UpdateData(true);
	switch (m_Stiff)
	{
	case 0:
		OutStiff();
		break;
	case 1:	
		SetStiff();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedGroup5Radio()
{

	UpdateData(true);
	switch (m_Shoot)
	{
	case 0:
		OutShoot();
		break;
	case 1:
		SetShoot();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedGroup6Radio()
{

	UpdateData(true);
	switch (m_Armor)
	{
	case 0:
		OutArmor();
		break;
	case 1:
		SetArmor();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedGroup7Radio()
{

	UpdateData(true);
	switch (m_Weapon)
	{
	case 0:
		OutWeapon();
		break;
	case 1:
		SetWeapon();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedGroup8Radio()
{

	UpdateData(true);
	switch (m_View)
	{
	case 0:
		OutView();
		break;
	case 1:
		SetView();
		break;
	default:
		break;
	}

}

void HackDialog::OnBnClickedMoneyButton()
{
	// TODO: 在此添加控件通知处理程序代码
	SetMoney();
}


