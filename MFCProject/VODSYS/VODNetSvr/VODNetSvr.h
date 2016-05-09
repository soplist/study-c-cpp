// VODNetSvr.h : main header file for the VODNETSVR DLL
//

#if !defined(AFX_VODNETSVR_H__3A7DCBBA_2A63_4390_9FF2_45207ACC507F__INCLUDED_)
#define AFX_VODNETSVR_H__3A7DCBBA_2A63_4390_9FF2_45207ACC507F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVODNetSvrApp
// See VODNetSvr.cpp for the implementation of this class
//

class CVODNetSvrApp : public CWinApp
{
public:
	CVODNetSvrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVODNetSvrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CVODNetSvrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VODNETSVR_H__3A7DCBBA_2A63_4390_9FF2_45207ACC507F__INCLUDED_)
