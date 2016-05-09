// AdoCommand.cpp: implementation of the CAdoCommand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoCommand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoCommand::CAdoCommand()
{

}

CAdoCommand::~CAdoCommand()
{

}
BOOL CAdoCommand::OpenSql(CString strSql, 
					CAdoDatabase* pDatabase)
{
	//创建Command接口对象
	HRESULT nRet=
		m_pCmd.CreateInstance(__uuidof(Command));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	//设置数据库连接
	m_pCmd->ActiveConnection=pDatabase->m_pConn;
	//设置sql语句
	m_pCmd->CommandText=_bstr_t(strSql);
	//执行Sql语句
	m_pCmd->Execute(NULL,NULL,
		adCmdText|adExecuteNoRecords);
}