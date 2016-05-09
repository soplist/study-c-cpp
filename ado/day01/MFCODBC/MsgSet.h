#if !defined(AFX_MSGSET_H__06BCAD16_708C_4443_ADE7_265F9F16B5DD__INCLUDED_)
#define AFX_MSGSET_H__06BCAD16_708C_4443_ADE7_265F9F16B5DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsgSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsgSet recordset

class CMsgSet : public CRecordset
{
public:
	CMsgSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMsgSet)

// Field/Param Data
	//{{AFX_FIELD(CMsgSet, CRecordset)
	CString	m_MSG_ID;
	CString	m_MSG_SENDER;
	CString	m_MSG_RECEIVER;
	CString	m_MSG_DATE;
	CString	m_MSG_CONTENT;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsgSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSGSET_H__06BCAD16_708C_4443_ADE7_265F9F16B5DD__INCLUDED_)
