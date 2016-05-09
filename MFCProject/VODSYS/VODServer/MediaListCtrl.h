#if !defined(AFX_MEDIALISTCTRL_H__2D7D1766_32BD_4940_A7C4_4570C46019AE__INCLUDED_)
#define AFX_MEDIALISTCTRL_H__2D7D1766_32BD_4940_A7C4_4570C46019AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MediaListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMediaListCtrl window

class CMediaListCtrl : public CListCtrl
{
// Construction
public:
	CMediaListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMediaListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMediaListCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIALISTCTRL_H__2D7D1766_32BD_4940_A7C4_4570C46019AE__INCLUDED_)
