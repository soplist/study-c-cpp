// MFCODBC.h : main header file for the MFCODBC application
//

#if !defined(AFX_MFCODBC_H__9009C527_1DD5_4509_9F0A_76E0A6B11F8D__INCLUDED_)
#define AFX_MFCODBC_H__9009C527_1DD5_4509_9F0A_76E0A6B11F8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCApp:
// See MFCODBC.cpp for the implementation of this class
//

class CMFCODBCApp : public CWinApp
{
public:
	CMFCODBCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCODBCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCODBCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCODBC_H__9009C527_1DD5_4509_9F0A_76E0A6B11F8D__INCLUDED_)
