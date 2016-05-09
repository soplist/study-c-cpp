// VODPlayerDoc.cpp : implementation of the CVODPlayerDoc class
//

#include "stdafx.h"
#include "VODPlayer.h"

#include "VODPlayerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerDoc

IMPLEMENT_DYNCREATE(CVODPlayerDoc, CDocument)

BEGIN_MESSAGE_MAP(CVODPlayerDoc, CDocument)
	//{{AFX_MSG_MAP(CVODPlayerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CVODPlayerDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CVODPlayerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IVODPlayer to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {C074A565-A3A6-4D2D-A4FD-AAAADA79D18D}
static const IID IID_IVODPlayer =
{ 0xc074a565, 0xa3a6, 0x4d2d, { 0xa4, 0xfd, 0xaa, 0xaa, 0xda, 0x79, 0xd1, 0x8d } };

BEGIN_INTERFACE_MAP(CVODPlayerDoc, CDocument)
	INTERFACE_PART(CVODPlayerDoc, IID_IVODPlayer, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerDoc construction/destruction

CVODPlayerDoc::CVODPlayerDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CVODPlayerDoc::~CVODPlayerDoc()
{
	AfxOleUnlockApp();
}

BOOL CVODPlayerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVODPlayerDoc serialization

void CVODPlayerDoc::Serialize(CArchive& ar)
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
// CVODPlayerDoc diagnostics

#ifdef _DEBUG
void CVODPlayerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVODPlayerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerDoc commands
