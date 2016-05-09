// AdoDatabase.cpp: implementation of the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoDatabase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoDatabase::CAdoDatabase()
{

}

CAdoDatabase::~CAdoDatabase()
{
   Close();
}
BOOL CAdoDatabase::OpenMDB(CString strPath)
{
	//创建Connection接口对象
	int nRet=
	 m_pConn.CreateInstance(__uuidof(Connection));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	//构造连接字符串
	CString strConn;
	strConn.Format("Provider=Microsoft.Jet.OLEDB.4.0;"
		"Data Source=%s;User ID=;Password=;",strPath);
	nRet=m_pConn->Open(_bstr_t(strConn),"","",0);
	if (FAILED(nRet))
	{
		m_pConn.Release();
		return FALSE;
	}
	return TRUE;
}
void CAdoDatabase::Close()
{
	if (m_pConn)
	{
		m_pConn->Close();
	}
}
BOOL CAdoDatabase::OpenSql(CString strSql)
{
	if (m_pConn)
	{
		HRESULT nRet=
		  m_pConn->Execute(_bstr_t(strSql),NULL,
			adCmdText|adExecuteNoRecords);
		if (SUCCEEDED(nRet))
		{
			return TRUE;
		}
	}
	return FALSE;
}
BOOL CAdoDatabase::BeginTrans()
{
	if (m_pConn)
	{
		if (SUCCEEDED(m_pConn->BeginTrans()))
		{
			return TRUE;
		}
	}
	return FALSE;
}
BOOL CAdoDatabase::EndTrans(BOOL bCommit/* =TRUE */)
{
	if (m_pConn)
	{
		HRESULT nRet=S_OK;
		if (bCommit)
		{
			nRet=m_pConn->CommitTrans();
		}
		else
		{
			nRet=m_pConn->RollbackTrans();
		}
		if (SUCCEEDED(nRet))
		{
			return TRUE;
		}

	}
	return FALSE;
}

