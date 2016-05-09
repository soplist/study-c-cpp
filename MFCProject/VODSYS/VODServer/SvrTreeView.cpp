// SvrTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "VODServer.h"
#include "SvrTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSvrTreeView

IMPLEMENT_DYNCREATE(CSvrTreeView, CTreeView)

CSvrTreeView::CSvrTreeView()
{
}

CSvrTreeView::~CSvrTreeView()
{
}


BEGIN_MESSAGE_MAP(CSvrTreeView, CTreeView)
	//{{AFX_MSG_MAP(CSvrTreeView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSvrTreeView drawing

void CSvrTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSvrTreeView diagnostics

#ifdef _DEBUG
void CSvrTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSvrTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSvrTreeView message handlers

int CSvrTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CTreeCtrl & theCtrl=GetTreeCtrl();
	HTREEITEM hRoot=theCtrl.InsertItem("VOD 服务器");
	theCtrl.InsertItem("用户管理",hRoot);
	theCtrl.InsertItem("媒体管理",hRoot);
	theCtrl.SetItemHeight(25);
	theCtrl.Expand(hRoot,TVE_EXPAND);
	return 0;
}
