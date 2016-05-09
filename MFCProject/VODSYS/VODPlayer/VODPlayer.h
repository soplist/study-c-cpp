// VODPlayer.h : main header file for the VODPLAYER application
//

#if !defined(AFX_VODPLAYER_H__6B49BB3D_6FCD_4775_B14B_8CB301530D40__INCLUDED_)
#define AFX_VODPLAYER_H__6B49BB3D_6FCD_4775_B14B_8CB301530D40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVODPlayerApp:
// See VODPlayer.cpp for the implementation of this class
//

class CVODPlayerApp : public CWinApp
{
public:
	CVODPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CVODPlayerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODPLAYER_H__6B49BB3D_6FCD_4775_B14B_8CB301530D40__INCLUDED_)
