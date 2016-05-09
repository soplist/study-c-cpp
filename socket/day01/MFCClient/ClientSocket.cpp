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
	//����
	if (!Create())
	{
		return FALSE;
	}
	//���ӷ�����
    return Connect(pszIP,nPort);
}
typedef struct _tagHeader
{
	DWORD nLen;//�ļ�����
	CHAR szFile[MAX_PATH];//�ļ�·��
}HEADER,*LPHEADER;
BOOL CClientSocket::SendFile(CString strPath)
{
	
	CFile file;
	file.Open(strPath,CFile::modeRead);
	//��ȡ�ļ�����
	DWORD nLen=file.GetLength();
	//��ȡ�ļ����ݱ��浽������
	LPBYTE pData=(LPBYTE)malloc(nLen);
	file.Read(pData,nLen);
	file.Close();
	//���ȷ������ݰ���ͷ
    HEADER header={0};
	header.nLen=nLen;
	strcpy(header.szFile,strPath);
	BOOL bRet=SendData((BYTE*)&header,sizeof(header));
	//Ȼ�����ļ�����
	bRet=SendData(pData,nLen);
	free(pData);
	return bRet;

}
BOOL CClientSocket::SendData(BYTE* pData,DWORD nLen)
{
	LPBYTE pTmpData=pData;//��ǰҪ���͵����ݵĵ�ַ
	DWORD nLeft=nLen;//��ǰδ���͵����ݳ���
	while(nLeft>0)
	{
		//�������ݣ����ҷ���ʵ�ʷ��͵����ݳ���
		int nSend=CAsyncSocket::Send(pTmpData,nLeft);
		if (nSend==SOCKET_ERROR)
		{
			return FALSE;
		}
		//���¼���ʣ��û�з��͵�������
		nLeft=nLeft-nSend;
		//������ָ��ƫ���Ѿ����͵�������
		pTmpData=pTmpData+nSend;
	}
	return TRUE;
}