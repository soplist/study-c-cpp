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
	//�򿪱�
	BOOL OpenTable(CString strTable,
		CAdoDatabase* pDatabase);
	//��ȡ�ֶ�����
	UINT GetFieldsCount();
	//��ȡ�ֶε�����
	CString GetFieldName(long nIndex);
	//�α����
	void MoveFirst();
	void MoveLast();
	void MoveNext();
	void MovePrevious();
	void Move(LONG nIndex);
	BOOL IsEOF();
	//��ȡ/�����ֶε�ֵ
	BOOL GetValue(LONG nIndex,CString & strValue);
	BOOL SetValue(LONG nIndex,CString strValue);
	//��ȡ/���ö�������ֵ
	BOOL SetBinaryValue(LONG nIndex,BYTE* pData,
		ULONG nLen);
    BOOL GetBinaryValue(LONG nIndex,BYTE* pData,
		ULONG & nLen);
	//�������
	BOOL AddNew();
	//���µ����ݿ�
	void Update();
	//ɾ��
	BOOL Delete();
	//ִ��SQL���
	BOOL OpenSql(CString strSql,CAdoDatabase* pDatabase);

public:
	_RecordsetPtr m_pRecordset;//��¼������
};

#endif // !defined(AFX_ADORECORDSET_H__A9E4CEDA_511B_4C95_83DD_CFC7A9E7B123__INCLUDED_)
