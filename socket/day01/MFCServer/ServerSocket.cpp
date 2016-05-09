// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions
BOOL CServerSocket::InitServer(WORD nPort)
{
    //创建、绑定
	if(!Create(nPort))
	{
       return FALSE;
	}
	//监听
	return Listen();
    
}

typedef struct _tagHeader
{
  DWORD nLen;//文件长度
  CHAR szFile[MAX_PATH];//文件路径
}HEADER,*LPHEADER;
void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//接收客户端连接
    CSocket client;
	Accept(client);
	//收发数据

    //接收数据包的包头
	HEADER header={0};
    RecvData(client,(BYTE*)&header,sizeof(header));
	//根据包头中的文件路径构造文件的服务器路径
     CString strFileName=header.szFile;
	 int nFind=strFileName.ReverseFind('\\');
     strFileName=strFileName.Mid(nFind+1);
	 CString strPath="c:\\"+strFileName;
	 AfxMessageBox(strPath);
	//根据包头中的文件长度，接受文件数据
    RecvFile(client,strPath,header.nLen);
	CAsyncSocket::OnAccept(nErrorCode);
}
BOOL CServerSocket::RecvFile(CSocket & client, 
							 CString strFile,DWORD nLen)
{
   //接收数据保存到缓冲区
   BYTE* pData=(BYTE*)malloc(nLen);
   RecvData(client,pData,nLen);
   //将缓冲去数据保存到文件
   CFile file;
   file.Open(strFile,CFile::modeCreate|CFile::modeWrite);
   file.Write(pData,nLen);
   file.Close();
   free(pData);
   return TRUE;
}
BOOL CServerSocket::RecvData(CSocket & client, 
							 BYTE* pData,DWORD nLen)
{
   LPBYTE pTmpData=pData;//当前要存放数据的缓冲区地址
   DWORD nLeft=nLen;//当前未接收的数据的长度
   while(nLeft>0)
   {
	   //接收剩余数据，并返回当次接收的实际数据长度
	   int nRecv=client.Receive(pTmpData,nLeft);
	   if (nRecv==SOCKET_ERROR)
	   {
		   return FALSE;
	   }
	   //重新计算剩余的数据长度
       nLeft=nLeft-nRecv;
	   //将数据指针偏移已经接受的数据量
	   pTmpData=pTmpData+nRecv;
   }
   return TRUE;


}

