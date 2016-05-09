// VODPlayerView.h : interface of the CVODPlayerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VODPLAYERVIEW_H__CBA52D12_1BFE_4AAB_8905_97D197744E71__INCLUDED_)
#define AFX_VODPLAYERVIEW_H__CBA52D12_1BFE_4AAB_8905_97D197744E71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVODPlayerView : public CFormView
{
protected: // create from serialization only
	CVODPlayerView();
	DECLARE_DYNCREATE(CVODPlayerView)

public:
	//{{AFX_DATA(CVODPlayerView)
	enum{ IDD = IDD_VODPLAYER_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CVODPlayerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODPlayerView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVODPlayerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVODPlayerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VODPlayerView.cpp
inline CVODPlayerDoc* CVODPlayerView::GetDocument()
   { return (CVODPlayerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODPLAYERVIEW_H__CBA52D12_1BFE_4AAB_8905_97D197744E71__INCLUDED_)
