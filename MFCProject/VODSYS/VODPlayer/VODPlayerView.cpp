// VODPlayerView.cpp : implementation of the CVODPlayerView class
//

#include "stdafx.h"
#include "VODPlayer.h"

#include "VODPlayerDoc.h"
#include "VODPlayerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerView

IMPLEMENT_DYNCREATE(CVODPlayerView, CFormView)

BEGIN_MESSAGE_MAP(CVODPlayerView, CFormView)
	//{{AFX_MSG_MAP(CVODPlayerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerView construction/destruction

CVODPlayerView::CVODPlayerView()
	: CFormView(CVODPlayerView::IDD)
{
	//{{AFX_DATA_INIT(CVODPlayerView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CVODPlayerView::~CVODPlayerView()
{
}

void CVODPlayerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVODPlayerView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CVODPlayerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CVODPlayerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerView diagnostics

#ifdef _DEBUG
void CVODPlayerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CVODPlayerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CVODPlayerDoc* CVODPlayerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVODPlayerDoc)));
	return (CVODPlayerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerView message handlers
