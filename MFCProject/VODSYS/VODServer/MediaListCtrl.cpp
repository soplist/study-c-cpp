// MediaListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "VODServer.h"
#include "MediaListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMediaListCtrl

CMediaListCtrl::CMediaListCtrl()
{
}

CMediaListCtrl::~CMediaListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMediaListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CMediaListCtrl)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMediaListCtrl message handlers

int CMediaListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	InsertColumn(0,"媒体名称",LVCFMT_LEFT,150);
	InsertColumn(1,"媒体类型",LVCFMT_LEFT,150);
	InsertColumn(2,"媒体描述",LVCFMT_LEFT,150);
	InsertColumn(3,"文件路径",LVCFMT_LEFT,150);

	return 0;
}
