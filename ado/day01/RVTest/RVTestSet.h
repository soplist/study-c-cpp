// RVTestSet.h : interface of the CRVTestSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RVTESTSET_H__43BBE5FD_A4F4_4DFB_AEC1_B8A5A8E018B7__INCLUDED_)
#define AFX_RVTESTSET_H__43BBE5FD_A4F4_4DFB_AEC1_B8A5A8E018B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRVTestSet : public CRecordset
{
public:
	CRVTestSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRVTestSet)

// Field/Param Data
	//{{AFX_FIELD(CRVTestSet, CRecordset)
	CString	m_MSG_ID;
	CString	m_MSG_SENDER;
	CString	m_MSG_RECEIVER;
	CString	m_MSG_DATE;
	CString	m_MSG_CONTENT;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRVTestSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RVTESTSET_H__43BBE5FD_A4F4_4DFB_AEC1_B8A5A8E018B7__INCLUDED_)

