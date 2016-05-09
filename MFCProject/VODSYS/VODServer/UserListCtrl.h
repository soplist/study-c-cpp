#if !defined(AFX_USERLISTCTRL_H__C49263A6_8097_4965_91B9_40E89F367F0E__INCLUDED_)
#define AFX_USERLISTCTRL_H__C49263A6_8097_4965_91B9_40E89F367F0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserListCtrl window

class CUserListCtrl : public CListCtrl
{
// Construction
public:
	CUserListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUserListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CUserListCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERLISTCTRL_H__C49263A6_8097_4965_91B9_40E89F367F0E__INCLUDED_)
