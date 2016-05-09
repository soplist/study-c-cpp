#if !defined(AFX_SVRLISTVIEW_H__FBE8A7D4_6EAC_49C6_B6E6_5A31F42BB37B__INCLUDED_)
#define AFX_SVRLISTVIEW_H__FBE8A7D4_6EAC_49C6_B6E6_5A31F42BB37B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SvrListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSvrListView view
#define SLVIEW_USERLIST 0
#define SLVIEW_MEDIALIST 1
#include "UserListCtrl.h"
#include "MediaListCtrl.h" 
class CSvrListView : public CView
{
protected:
	CSvrListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSvrListView)

// Attributes
public:
   CMediaListCtrl m_wndMedia;
   CUserListCtrl  m_wndUser;
   CListCtrl* m_pWndActive;//指向当前活动控件
// Operations
public:
   void SwitchView(int nView);
   void FullView();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSvrListView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSvrListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSvrListView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SVRLISTVIEW_H__FBE8A7D4_6EAC_49C6_B6E6_5A31F42BB37B__INCLUDED_)
