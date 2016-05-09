// RVTestView.cpp : implementation of the CRVTestView class
//

#include "stdafx.h"
#include "RVTest.h"

#include "RVTestSet.h"
#include "RVTestDoc.h"
#include "RVTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRVTestView

IMPLEMENT_DYNCREATE(CRVTestView, CRecordView)

BEGIN_MESSAGE_MAP(CRVTestView, CRecordView)
	//{{AFX_MSG_MAP(CRVTestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRVTestView construction/destruction

CRVTestView::CRVTestView()
	: CRecordView(CRVTestView::IDD)
{
	//{{AFX_DATA_INIT(CRVTestView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CRVTestView::~CRVTestView()
{
}

void CRVTestView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRVTestView)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_MSG_ID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_MSG_SENDER, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_MSG_RECEIVER, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_MSG_CONTENT, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_MSG_DATE, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CRVTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CRVTestView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_rVTestSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CRVTestView printing

BOOL CRVTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRVTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRVTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRVTestView diagnostics

#ifdef _DEBUG
void CRVTestView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CRVTestView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CRVTestDoc* CRVTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRVTestDoc)));
	return (CRVTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRVTestView database support
CRecordset* CRVTestView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CRVTestView message handlers
