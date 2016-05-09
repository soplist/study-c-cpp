// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions
BOOL CClientSocket::InitClient(CHAR* pszIP,WORD nPort)
{
	//创建
	if (!Create())
	{
		return FALSE;
	}
	//连接服务器
    return Connect(pszIP,nPort);
}
typedef struct _tagHeader
{
	DWORD nLen;//文件长度
	CHAR szFile[MAX_PATH];//文件路径
}HEADER,*LPHEADER;
BOOL CClientSocket::SendFile(CString strPath)
{
	
	CFile file;
	file.Open(strPath,CFile::modeRead);
	//获取文件长度
	DWORD nLen=file.GetLength();
	//获取文件数据保存到缓冲区
	LPBYTE pData=(LPBYTE)malloc(nLen);
	file.Read(pData,nLen);
	file.Close();
	//首先发送数据包包头
    HEADER header={0};
	header.nLen=nLen;
	strcpy(header.szFile,strPath);
	BOOL bRet=SendData((BYTE*)&header,sizeof(header));
	//然后发送文件数据
	bRet=SendData(pData,nLen);
	free(pData);
	return bRet;

}
BOOL CClientSocket::SendData(BYTE* pData,DWORD nLen)
{
	LPBYTE pTmpData=pData;//当前要发送的数据的地址
	DWORD nLeft=nLen;//当前未发送的数据长度
	while(nLeft>0)
	{
		//发送数据，并且返回实际发送的数据长度
		int nSend=CAsyncSocket::Send(pTmpData,nLeft);
		if (nSend==SOCKET_ERROR)
		{
			return FALSE;
		}
		//重新计算剩余没有发送的数据量
		nLeft=nLeft-nSend;
		//将数据指针偏移已经发送的数据量
		pTmpData=pTmpData+nSend;
	}
	return TRUE;
}