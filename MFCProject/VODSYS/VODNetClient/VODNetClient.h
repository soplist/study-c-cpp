// VODNetClient.h : main header file for the VODNETCLIENT DLL
//

#if !defined(AFX_VODNETCLIENT_H__3969592D_CE6C_4064_B454_D067537A331B__INCLUDED_)
#define AFX_VODNETCLIENT_H__3969592D_CE6C_4064_B454_D067537A331B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVODNetClientApp
// See VODNetClient.cpp for the implementation of this class
//

class CVODNetClientApp : public CWinApp
{
public:
	CVODNetClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODNetClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CVODNetClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODNETCLIENT_H__3969592D_CE6C_4064_B454_D067537A331B__INCLUDED_)
