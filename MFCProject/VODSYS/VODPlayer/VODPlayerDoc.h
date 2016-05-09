// VODPlayerDoc.h : interface of the CVODPlayerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VODPLAYERDOC_H__ED806480_3E25_4B0E_B574_FBF8755181E6__INCLUDED_)
#define AFX_VODPLAYERDOC_H__ED806480_3E25_4B0E_B574_FBF8755181E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVODPlayerDoc : public CDocument
{
protected: // create from serialization only
	CVODPlayerDoc();
	DECLARE_DYNCREATE(CVODPlayerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODPlayerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVODPlayerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVODPlayerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CVODPlayerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODPLAYERDOC_H__ED806480_3E25_4B0E_B574_FBF8755181E6__INCLUDED_)
