// WinMenu.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMainFrame:public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct ); 
	afx_msg void OnOpen();
	afx_msg void OnUpdateCmdUIOpen(CCmdUI* pCmdUI);
};
void CMainFrame::OnUpdateCmdUIOpen(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(1);
}
void CMainFrame::OnOpen()
{
	MessageBox("CMainFrame::OnOpen");
}
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//通常会先调用父类的OnCreate函数
	if(-1 == CFrameWnd::OnCreate(lpCreateStruct))
	{
		return -1;
	}
	//添加自己的代码
	CMenu menu;
	//加载菜单资源(menu与HMENU产生映射关系)
	menu.LoadMenu(IDR_MAINFRM);
	//把菜单设置到窗口
	SetMenu(&menu);
	//将menu对象与菜单句柄分离
	menu.Detach();

	return 0;
}
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_CREATE()
	ON_COMMAND(ID_OPEN, OnOpen)
	ON_UPDATE_COMMAND_UI(ID_OPEN, OnUpdateCmdUIOpen)
END_MESSAGE_MAP()

class CMenuApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnOpen();
};
BEGIN_MESSAGE_MAP(CMenuApp, CWinApp)
	ON_COMMAND(ID_OPEN, OnOpen)
END_MESSAGE_MAP()
CMenuApp theApp;
void CMenuApp::OnOpen()
{
	AfxMessageBox("CMenuApp:public CWinApp");
}
BOOL CMenuApp::InitInstance()
{
	CMainFrame* pFrame = new CMainFrame;
	pFrame->Create(NULL, "MFCMenu");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}
