// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__A9E4CEDA_511B_4C95_83DD_CFC7A9E7B123__INCLUDED_)
#define AFX_ADORECORDSET_H__A9E4CEDA_511B_4C95_83DD_CFC7A9E7B123__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdoRecordset  
{
public:
	CAdoRecordset();
	virtual ~CAdoRecordset();
	//打开表
	BOOL OpenTable(CString strTable,
		CAdoDatabase* pDatabase);
	//获取字段数量
	UINT GetFieldsCount();
	//获取字段的名称
	CString GetFieldName(long nIndex);
	//游标操作
	void MoveFirst();
	void MoveLast();
	void MoveNext();
	void MovePrevious();
	void Move(LONG nIndex);
	BOOL IsEOF();
	//获取/设置字段的值
	BOOL GetValue(LONG nIndex,CString & strValue);
	BOOL SetValue(LONG nIndex,CString strValue);
	//获取/设置二进制数值
	BOOL SetBinaryValue(LONG nIndex,BYTE* pData,
		ULONG nLen);
    BOOL GetBinaryValue(LONG nIndex,BYTE* pData,
		ULONG & nLen);
	//添加新行
	BOOL AddNew();
	//更新到数据库
	void Update();
	//删除
	BOOL Delete();
	//执行SQL语句
	BOOL OpenSql(CString strSql,CAdoDatabase* pDatabase);

public:
	_RecordsetPtr m_pRecordset;//记录集对象
};

#endif // !defined(AFX_ADORECORDSET_H__A9E4CEDA_511B_4C95_83DD_CFC7A9E7B123__INCLUDED_)
