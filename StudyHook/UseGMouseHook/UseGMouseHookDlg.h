// UseGMouseHookDlg.h : header file
//

#if !defined(AFX_USEGMOUSEHOOKDLG_H__CCE5FF20_F9D6_4F9C_8FD9_2618B3377045__INCLUDED_)
#define AFX_USEGMOUSEHOOKDLG_H__CCE5FF20_F9D6_4F9C_8FD9_2618B3377045__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseGMouseHookDlg dialog
#include "../GMouseHook/Mousehook.h"
#pragma comment(lib,"../GMouseHook/debug/GMouseHook.lib")
class CUseGMouseHookDlg : public CDialog
{
// Construction
public:
	CUseGMouseHookDlg(CWnd* pParent = NULL);	// standard constructor
    Cmousehook m_hook;
// Dialog Data
	//{{AFX_DATA(CUseGMouseHookDlg)
	enum { IDD = IDD_USEGMOUSEHOOK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseGMouseHookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseGMouseHookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEGMOUSEHOOKDLG_H__CCE5FF20_F9D6_4F9C_8FD9_2618B3377045__INCLUDED_)
