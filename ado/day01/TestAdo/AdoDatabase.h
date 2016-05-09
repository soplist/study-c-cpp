// AdoDatabase.h: interface for the CAdoDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATABASE_H__97027370_EC98_48D5_9728_B0E01552EB13__INCLUDED_)
#define AFX_ADODATABASE_H__97027370_EC98_48D5_9728_B0E01552EB13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdoDatabase  
{
public:
	CAdoDatabase();
	virtual ~CAdoDatabase();
public:
	BOOL OpenMDB(CString strPath);
	void Close();
	//执行Sql语句
	BOOL OpenSql(CString strSql);
	//事务处理
	BOOL BeginTrans();
	BOOL EndTrans(BOOL bCommit=TRUE);
public:
	_ConnectionPtr m_pConn;//接口对象
};

#endif // !defined(AFX_ADODATABASE_H__97027370_EC98_48D5_9728_B0E01552EB13__INCLUDED_)
