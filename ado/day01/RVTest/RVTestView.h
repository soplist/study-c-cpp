// RVTestView.h : interface of the CRVTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RVTESTVIEW_H__71473FCB_4EC6_447E_A754_EA3FD571DAFC__INCLUDED_)
#define AFX_RVTESTVIEW_H__71473FCB_4EC6_447E_A754_EA3FD571DAFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRVTestSet;

class CRVTestView : public CRecordView
{
protected: // create from serialization only
	CRVTestView();
	DECLARE_DYNCREATE(CRVTestView)

public:
	//{{AFX_DATA(CRVTestView)
	enum { IDD = IDD_RVTEST_FORM };
	CRVTestSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CRVTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRVTestView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRVTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRVTestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RVTestView.cpp
inline CRVTestDoc* CRVTestView::GetDocument()
   { return (CRVTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RVTESTVIEW_H__71473FCB_4EC6_447E_A754_EA3FD571DAFC__INCLUDED_)
