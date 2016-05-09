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
	//ִ��Sql���
	BOOL OpenSql(CString strSql);
	//������
	BOOL BeginTrans();
	BOOL EndTrans(BOOL bCommit=TRUE);
public:
	_ConnectionPtr m_pConn;//�ӿڶ���
};

#endif // !defined(AFX_ADODATABASE_H__97027370_EC98_48D5_9728_B0E01552EB13__INCLUDED_)
