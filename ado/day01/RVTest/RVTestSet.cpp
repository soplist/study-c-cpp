// RVTestSet.cpp : implementation of the CRVTestSet class
//

#include "stdafx.h"
#include "RVTest.h"
#include "RVTestSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRVTestSet implementation

IMPLEMENT_DYNAMIC(CRVTestSet, CRecordset)

CRVTestSet::CRVTestSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRVTestSet)
	m_MSG_ID = _T("");
	m_MSG_SENDER = _T("");
	m_MSG_RECEIVER = _T("");
	m_MSG_DATE = _T("");
	m_MSG_CONTENT = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CRVTestSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Test");
}

CString CRVTestSet::GetDefaultSQL()
{
	return _T("[TBL_MSG]");
}

void CRVTestSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRVTestSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[MSG_ID]"), m_MSG_ID);
	RFX_Text(pFX, _T("[MSG_SENDER]"), m_MSG_SENDER);
	RFX_Text(pFX, _T("[MSG_RECEIVER]"), m_MSG_RECEIVER);
	RFX_Text(pFX, _T("[MSG_DATE]"), m_MSG_DATE);
	RFX_Text(pFX, _T("[MSG_CONTENT]"), m_MSG_CONTENT);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRVTestSet diagnostics

#ifdef _DEBUG
void CRVTestSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRVTestSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
