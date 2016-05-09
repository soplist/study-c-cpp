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
	//ͨ�����ȵ��ø����OnCreate����
	if(-1 == CFrameWnd::OnCreate(lpCreateStruct))
	{
		return -1;
	}
	//����Լ��Ĵ���
	CMenu menu;
	//���ز˵���Դ(menu��HMENU����ӳ���ϵ)
	menu.LoadMenu(IDR_MAINFRM);
	//�Ѳ˵����õ�����
	SetMenu(&menu);
	//��menu������˵��������
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
