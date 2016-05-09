// UseGMouseHook.h : main header file for the USEGMOUSEHOOK application
//

#if !defined(AFX_USEGMOUSEHOOK_H__7DD54540_5CEE_46BD_9FFC_3B96DFADCDF7__INCLUDED_)
#define AFX_USEGMOUSEHOOK_H__7DD54540_5CEE_46BD_9FFC_3B96DFADCDF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseGMouseHookApp:
// See UseGMouseHook.cpp for the implementation of this class
//

class CUseGMouseHookApp : public CWinApp
{
public:
	CUseGMouseHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseGMouseHookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseGMouseHookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEGMOUSEHOOK_H__7DD54540_5CEE_46BD_9FFC_3B96DFADCDF7__INCLUDED_)
