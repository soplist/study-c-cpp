#if !defined(AFX_CLIENTSOCKET_H__250F72E7_904F_4C74_AD2F_08D25849B087__INCLUDED_)
#define AFX_CLIENTSOCKET_H__250F72E7_904F_4C74_AD2F_08D25849B087__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();
public:
	BOOL InitClient(CHAR* pszIP,WORD nPort);
    BOOL SendFile(CString strPath);
	BOOL SendData(BYTE* pData,DWORD nLen);

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__250F72E7_904F_4C74_AD2F_08D25849B087__INCLUDED_)
