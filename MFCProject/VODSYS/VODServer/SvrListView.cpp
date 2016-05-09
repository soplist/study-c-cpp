// SvrListView.cpp : implementation file
//

#include "stdafx.h"
#include "VODServer.h"
#include "SvrListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSvrListView

IMPLEMENT_DYNCREATE(CSvrListView, CView)

CSvrListView::CSvrListView()
{
	 m_pWndActive=NULL;
}

CSvrListView::~CSvrListView()
{
}


BEGIN_MESSAGE_MAP(CSvrListView, CView)
	//{{AFX_MSG_MAP(CSvrListView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSvrListView drawing

void CSvrListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSvrListView diagnostics

#ifdef _DEBUG
void CSvrListView::AssertValid() const
{
	CView::AssertValid();
}

void CSvrListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSvrListView message handlers
void CSvrListView::SwitchView(int nView)
{
	//指向将要创建或者显示的控件
	CListCtrl* pTmpCtrl=NULL;
	switch (nView)
	{
	case SLVIEW_MEDIALIST:
		pTmpCtrl=&m_wndMedia;
		break;
	case SLVIEW_USERLIST:
		pTmpCtrl=&m_wndUser;
		break;
	default:
		return;
	}
	//判断控件的窗口是否被创建
	if(!IsWindow(pTmpCtrl->GetSafeHwnd()))
	{
       //创建控件的窗口
		pTmpCtrl->Create(WS_CHILD|WS_VISIBLE|LVS_REPORT,
			CRect(0,0,0,0),this,1);
	}
	//如果存在当前活动控件，隐藏控件
	if (m_pWndActive!=NULL)
	{
		m_pWndActive->ShowWindow(SW_HIDE);
	}
	//将新建的控件设置为当前活动控件
	m_pWndActive=pTmpCtrl;
    m_pWndActive->ShowWindow(SW_SHOW);
    //将控件铺满整个CSvrListView
	FullView();
}
void CSvrListView::FullView()
{
	if (m_pWndActive==NULL)return;
	CRect rcClient;
	//获取CSvrListView的客户区大小
	GetClientRect(&rcClient);
	//设置给控件
	m_pWndActive->MoveWindow(0,0,rcClient.Width(),
		rcClient.Height());
}

void CSvrListView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	FullView();
	// TODO: Add your message handler code here
	
}
