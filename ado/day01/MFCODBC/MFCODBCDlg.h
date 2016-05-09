// MFCODBCDlg.h : header file
//

#if !defined(AFX_MFCODBCDLG_H__B11AE319_CCE9_4DEC_B6AF_DCC60AE14A84__INCLUDED_)
#define AFX_MFCODBCDLG_H__B11AE319_CCE9_4DEC_B6AF_DCC60AE14A84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCDlg dialog

class CMFCODBCDlg : public CDialog
{
// Construction
public:
	void ShowData(CRecordset* pSet);
	CMFCODBCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCODBCDlg)
	enum { IDD = IDD_MFCODBC_DIALOG };
	CListCtrl	m_wndList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCODBCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCODBCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShow();
	afx_msg void OnBind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCODBCDLG_H__B11AE319_CCE9_4DEC_B6AF_DCC60AE14A84__INCLUDED_)
