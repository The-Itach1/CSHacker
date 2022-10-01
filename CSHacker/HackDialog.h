#pragma once


// HackDialog 对话框

class HackDialog : public CDialog
{
	DECLARE_DYNAMIC(HackDialog)

public:
	HackDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HackDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Bullets;
	BOOL m_HP;
	BOOL m_Armor;
	BOOL m_Shop;
	BOOL m_Stiff;
	BOOL m_Shoot;
	BOOL m_Weapon;
	CButton m_Money;
	virtual BOOL OnInitDialog();
	virtual INT_PTR DoModal();
	afx_msg void OnBnClickedGroup1Radio();
	afx_msg void OnBnClickedGroup2Radio();
	afx_msg void OnBnClickedGroup3Radio();
	afx_msg void OnBnClickedGroup4Radio();
	afx_msg void OnBnClickedGroup5Radio();
	afx_msg void OnBnClickedGroup6Radio();
	afx_msg void OnBnClickedGroup7Radio();
	afx_msg void OnBnClickedGroup8Radio();
	afx_msg void OnBnClickedMoneyButton();

	BOOL m_View;
};
