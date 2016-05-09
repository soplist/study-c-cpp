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
    //��������
	if(!Create(nPort))
	{
       return FALSE;
	}
	//����
	return Listen();
    
}

typedef struct _tagHeader
{
  DWORD nLen;//�ļ�����
  CHAR szFile[MAX_PATH];//�ļ�·��
}HEADER,*LPHEADER;
void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//���տͻ�������
    CSocket client;
	Accept(client);
	//�շ�����

    //�������ݰ��İ�ͷ
	HEADER header={0};
    RecvData(client,(BYTE*)&header,sizeof(header));
	//���ݰ�ͷ�е��ļ�·�������ļ��ķ�����·��
     CString strFileName=header.szFile;
	 int nFind=strFileName.ReverseFind('\\');
     strFileName=strFileName.Mid(nFind+1);
	 CString strPath="c:\\"+strFileName;
	 AfxMessageBox(strPath);
	//���ݰ�ͷ�е��ļ����ȣ������ļ�����
    RecvFile(client,strPath,header.nLen);
	CAsyncSocket::OnAccept(nErrorCode);
}
BOOL CServerSocket::RecvFile(CSocket & client, 
							 CString strFile,DWORD nLen)
{
   //�������ݱ��浽������
   BYTE* pData=(BYTE*)malloc(nLen);
   RecvData(client,pData,nLen);
   //������ȥ���ݱ��浽�ļ�
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
   LPBYTE pTmpData=pData;//��ǰҪ������ݵĻ�������ַ
   DWORD nLeft=nLen;//��ǰδ���յ����ݵĳ���
   while(nLeft>0)
   {
	   //����ʣ�����ݣ������ص��ν��յ�ʵ�����ݳ���
	   int nRecv=client.Receive(pTmpData,nLeft);
	   if (nRecv==SOCKET_ERROR)
	   {
		   return FALSE;
	   }
	   //���¼���ʣ������ݳ���
       nLeft=nLeft-nRecv;
	   //������ָ��ƫ���Ѿ����ܵ�������
	   pTmpData=pTmpData+nRecv;
   }
   return TRUE;


}

