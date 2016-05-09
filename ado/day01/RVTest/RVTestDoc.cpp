// RVTestDoc.cpp : implementation of the CRVTestDoc class
//

#include "stdafx.h"
#include "RVTest.h"

#include "RVTestSet.h"
#include "RVTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRVTestDoc

IMPLEMENT_DYNCREATE(CRVTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CRVTestDoc, CDocument)
	//{{AFX_MSG_MAP(CRVTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRVTestDoc construction/destruction

CRVTestDoc::CRVTestDoc()
{
	// TODO: add one-time construction code here

}

CRVTestDoc::~CRVTestDoc()
{
}

BOOL CRVTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRVTestDoc serialization

void CRVTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRVTestDoc diagnostics

#ifdef _DEBUG
void CRVTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRVTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRVTestDoc commands
