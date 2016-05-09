// AdoCommand.h: interface for the CAdoCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCOMMAND_H__E50D4556_682F_4512_9FD7_2F9714D9CBCF__INCLUDED_)
#define AFX_ADOCOMMAND_H__E50D4556_682F_4512_9FD7_2F9714D9CBCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdoCommand  
{
public:
	CAdoCommand();
	virtual ~CAdoCommand();
	BOOL OpenSql(CString strSql,
		CAdoDatabase* pDatabase);
public:
	_CommandPtr m_pCmd;
};

#endif // !defined(AFX_ADOCOMMAND_H__E50D4556_682F_4512_9FD7_2F9714D9CBCF__INCLUDED_)
