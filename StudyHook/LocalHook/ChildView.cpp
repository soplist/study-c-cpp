// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "LocalHook.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView
HHOOK hHook;//��깳�Ӿ��
CPoint point;//���λ����Ϣ
CChildView* pView; 

LRESULT CALLBACK MouseProc (int nCode, WPARAM wParam, LPARAM lParam)

{   
	//�ж�������ƶ���Ϣ
	if(wParam==WM_MOUSEMOVE||wParam==WM_NCMOUSEMOVE)
	{
		//��ȡ���λ��
		point=((MOUSEHOOKSTRUCT*)lParam)->pt;
		//�ػ洰��
		pView->Invalidate();
	}
	//���ݹ�����Ϣ
	return CallNextHookEx(hHook,nCode,wParam,lParam);
	
}
CChildView::CChildView()
{
	pView=this;//����������ָ��
	//���ù���
    hHook=SetWindowsHookEx(WH_MOUSE,MouseProc,0,GetCurrentThreadId()); 
}

CChildView::~CChildView()
{
	//ж�ع���
	if(hHook)
	{
       UnhookWindowsHookEx(hHook); 
	}
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    CString strInfo;
	strInfo.Format("x=%d,y=%d;",point.x,point.y);
	dc.TextOut(100,100,strInfo);

}
 

