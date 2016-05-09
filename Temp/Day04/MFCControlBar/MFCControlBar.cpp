// MFCControlBar.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

//定义状态栏指示器数组
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
	CToolBar m_wndToolbar;//工具栏对象
	CStatusBar m_wndStatusbar;//状态栏对象
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
	//获取当前鼠标位置，并转换成字符串
	CString strPt;
	strPt.Format("X=%d, Y=%d", point.x, point.y);
	//设置到状态栏
	m_wndStatusbar.SetPaneText(0, strPt);
}
void CMainFrame::OnTimer(UINT nIDEvent)
{
	//获取当前系统时间
    CTime t = CTime::GetCurrentTime();
	//将时间以某种格式的字符串形式显示
	CString strTime = t.Format("%Y-%m-%d %H:%M:%S");
	//把字符串显示到状态栏上
	m_wndStatusbar.SetPaneText(1, strTime);
}
void CMainFrame::OnUpdateCmdUIToolBar(CCmdUI* pCmdUI)
{
	/*
	//判断工具栏是否是可见
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
	//判断工具栏是否是可见
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
	//创建工具栏
	m_wndToolbar.CreateEx(this, TBSTYLE_FLAT, CBRS_FLYBY | CBRS_TOOLTIPS | CBRS_GRIPPER | WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP);
	//加载工具栏
	m_wndToolbar.LoadToolBar(IDR_MAINFRAME);
	//停靠工具栏
	//1 设置工具栏允许停靠
	m_wndToolbar.EnableDocking(CBRS_ALIGN_TOP);
	//2 设置框架窗口允许停靠
	EnableDocking(CBRS_ALIGN_TOP);
	//3 停靠工具栏
	DockControlBar(&m_wndToolbar, AFX_IDW_DOCKBAR_TOP);
	//设置工具栏的标题
	m_wndToolbar.SetWindowText("标准");

	//创建状态栏
	m_wndStatusbar.Create(this);
	//设置状态栏指示器
    m_wndStatusbar.SetIndicators(g_nIndictors, sizeof(g_nIndictors)/sizeof(UINT));

    //设置定时器
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



