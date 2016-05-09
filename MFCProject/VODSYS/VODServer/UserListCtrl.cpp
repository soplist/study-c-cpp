// UserListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "VODServer.h"
#include "UserListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserListCtrl

CUserListCtrl::CUserListCtrl()
{
}

CUserListCtrl::~CUserListCtrl()
{
}


BEGIN_MESSAGE_MAP(CUserListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CUserListCtrl)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserListCtrl message handlers

int CUserListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	InsertColumn(0,"用户名称",LVCFMT_LEFT,150);
	InsertColumn(1,"描述",LVCFMT_LEFT,300);
	InsertColumn(2,"账户金额",LVCFMT_LEFT,150);

	return 0;
}
