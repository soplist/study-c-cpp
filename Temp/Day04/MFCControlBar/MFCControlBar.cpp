// MFCControlBar.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

//����״̬��ָʾ������
UINT g_nIndictors[] = {0, IDS_STRTIME, ID_INDICATOR_CAPS, ID_INDICATOR_NUM };
class CMainFrame:public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnOpen();
	afx_msg void OnExit();
	afx_msg void OnViewToolBar();
	afx_msg void OnUpdateCmdUIToolBar(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point); 

public:
	CToolBar m_wndToolbar;//����������
	CStatusBar m_wndStatusbar;//״̬������
};
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
  ON_WM_CREATE()
  ON_WM_TIMER()
  ON_COMMAND(ID_OPEN, OnOpen)
  ON_COMMAND(ID_EXIT, OnExit)
  ON_COMMAND(ID_VIEWTOOLBAR, OnViewToolBar)
  ON_UPDATE_COMMAND_UI(ID_VIEWTOOLBAR, OnUpdateCmdUIToolBar)
  ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()
void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	//��ȡ��ǰ���λ�ã���ת�����ַ���
	CString strPt;
	strPt.Format("X=%d, Y=%d", point.x, point.y);
	//���õ�״̬��
	m_wndStatusbar.SetPaneText(0, strPt);
}
void CMainFrame::OnTimer(UINT nIDEvent)
{
	//��ȡ��ǰϵͳʱ��
    CTime t = CTime::GetCurrentTime();
	//��ʱ����ĳ�ָ�ʽ���ַ�����ʽ��ʾ
	CString strTime = t.Format("%Y-%m-%d %H:%M:%S");
	//���ַ�����ʾ��״̬����
	m_wndStatusbar.SetPaneText(1, strTime);
}
void CMainFrame::OnUpdateCmdUIToolBar(CCmdUI* pCmdUI)
{
	/*
	//�жϹ������Ƿ��ǿɼ�
	if(m_wndToolbar.IsWindowVisible())
	{
		pCmdUI->SetCheck(1);
	}
	else 
	{
		pCmdUI->SetCheck(0);
	}*/
	pCmdUI->SetCheck(m_wndToolbar.IsWindowVisible());
	
}
void CMainFrame::OnViewToolBar()
{
	//�жϹ������Ƿ��ǿɼ�
	if(m_wndToolbar.IsWindowVisible())
	{
		ShowControlBar(&m_wndToolbar, FALSE, FALSE);
	}
	else 
	{
		ShowControlBar(&m_wndToolbar, TRUE, FALSE);
	}
}
void CMainFrame::OnOpen()
{
	MessageBox("CMainFrame::OnOpen");
}
void CMainFrame::OnExit()
{
	PostQuitMessage(0);
}
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (-1 == CFrameWnd::OnCreate(lpCreateStruct))
	{
		return -1;
	}
	//����������
	m_wndToolbar.CreateEx(this, TBSTYLE_FLAT, CBRS_FLYBY | CBRS_TOOLTIPS | CBRS_GRIPPER | WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP);
	//���ع�����
	m_wndToolbar.LoadToolBar(IDR_MAINFRAME);
	//ͣ��������
	//1 ���ù���������ͣ��
	m_wndToolbar.EnableDocking(CBRS_ALIGN_TOP);
	//2 ���ÿ�ܴ�������ͣ��
	EnableDocking(CBRS_ALIGN_TOP);
	//3 ͣ��������
	DockControlBar(&m_wndToolbar, AFX_IDW_DOCKBAR_TOP);
	//���ù������ı���
	m_wndToolbar.SetWindowText("��׼");

	//����״̬��
	m_wndStatusbar.Create(this);
	//����״̬��ָʾ��
    m_wndStatusbar.SetIndicators(g_nIndictors, sizeof(g_nIndictors)/sizeof(UINT));

    //���ö�ʱ��
	SetTimer(1, 1000, NULL);

	return 0;
}

class CToolBarApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CToolBarApp theApp;
BOOL CToolBarApp::InitInstance()
{
	CMainFrame* pFrame = new CMainFrame;
	pFrame->Create(NULL, "MFCToolBar", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, MAKEINTRESOURCE(IDR_MAINFRAME));
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}



