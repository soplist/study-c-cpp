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
	//ָ��Ҫ����������ʾ�Ŀؼ�
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
	//�жϿؼ��Ĵ����Ƿ񱻴���
	if(!IsWindow(pTmpCtrl->GetSafeHwnd()))
	{
       //�����ؼ��Ĵ���
		pTmpCtrl->Create(WS_CHILD|WS_VISIBLE|LVS_REPORT,
			CRect(0,0,0,0),this,1);
	}
	//������ڵ�ǰ��ؼ������ؿؼ�
	if (m_pWndActive!=NULL)
	{
		m_pWndActive->ShowWindow(SW_HIDE);
	}
	//���½��Ŀؼ�����Ϊ��ǰ��ؼ�
	m_pWndActive=pTmpCtrl;
    m_pWndActive->ShowWindow(SW_SHOW);
    //���ؼ���������CSvrListView
	FullView();
}
void CSvrListView::FullView()
{
	if (m_pWndActive==NULL)return;
	CRect rcClient;
	//��ȡCSvrListView�Ŀͻ�����С
	GetClientRect(&rcClient);
	//���ø��ؼ�
	m_pWndActive->MoveWindow(0,0,rcClient.Width(),
		rcClient.Height());
}

void CSvrListView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	FullView();
	// TODO: Add your message handler code here
	
}
