// CSHacker.cpp: 定义 DLL 的初始化例程。
//

#include "pch.h"
#include "framework.h"
#include "CSHacker.h"
#include "HackDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为以下项中的第一个语句:
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CCSHackerApp

BEGIN_MESSAGE_MAP(CCSHackerApp, CWinApp)
END_MESSAGE_MAP()


// CCSHackerApp 构造

CCSHackerApp::CCSHackerApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CCSHackerApp 对象

CCSHackerApp theApp;

HackDialog* mainDiaLog; //创建一个DiaLog的指针

DWORD WINAPI showDigLog(void* p)
{
    mainDiaLog = new HackDialog(); //给这个指针实例化
    mainDiaLog->DoModal(); //阻塞的方式显示这个DigLog
    delete mainDiaLog; //释放这个指针，具体可以查看我写的C++基础 使用指针实例类需要释放
    FreeLibraryAndExitThread(theApp.m_hInstance, 1); //释放线程
    return 0;
}


// CCSHackerApp 初始化

BOOL CCSHackerApp::InitInstance()
{
	CWinApp::InitInstance();

    HANDLE MyTheard = ::CreateThread(NULL, NULL, showDigLog, NULL, NULL, NULL);


	return TRUE;
}
