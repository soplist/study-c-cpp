// RVTestDoc.h : interface of the CRVTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RVTESTDOC_H__3F19FB2E_04B0_4210_839C_8CE15B8A5344__INCLUDED_)
#define AFX_RVTESTDOC_H__3F19FB2E_04B0_4210_839C_8CE15B8A5344__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RVTestSet.h"


class CRVTestDoc : public CDocument
{
protected: // create from serialization only
	CRVTestDoc();
	DECLARE_DYNCREATE(CRVTestDoc)

// Attributes
public:
	CRVTestSet m_rVTestSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRVTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRVTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRVTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RVTESTDOC_H__3F19FB2E_04B0_4210_839C_8CE15B8A5344__INCLUDED_)
