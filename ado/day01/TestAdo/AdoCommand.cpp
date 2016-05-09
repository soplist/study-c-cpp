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
	//����Command�ӿڶ���
	HRESULT nRet=
		m_pCmd.CreateInstance(__uuidof(Command));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	//�������ݿ�����
	m_pCmd->ActiveConnection=pDatabase->m_pConn;
	//����sql���
	m_pCmd->CommandText=_bstr_t(strSql);
	//ִ��Sql���
	m_pCmd->Execute(NULL,NULL,
		adCmdText|adExecuteNoRecords);
}