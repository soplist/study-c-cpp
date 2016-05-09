#if !defined(AFX_SVRTREEVIEW_H__EDE991D9_38AB_437E_A486_F7D9B29CB46C__INCLUDED_)
#define AFX_SVRTREEVIEW_H__EDE991D9_38AB_437E_A486_F7D9B29CB46C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SvrTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSvrTreeView view

class CSvrTreeView : public CTreeView
{
protected:
	CSvrTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSvrTreeView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSvrTreeView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSvrTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSvrTreeView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SVRTREEVIEW_H__EDE991D9_38AB_437E_A486_F7D9B29CB46C__INCLUDED_)
