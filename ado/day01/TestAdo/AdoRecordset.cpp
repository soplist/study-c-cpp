// AdoRecordset.cpp: implementation of the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestAdo.h"
#include "AdoRecordset.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoRecordset::CAdoRecordset()
{

}

CAdoRecordset::~CAdoRecordset()
{

}
BOOL CAdoRecordset::OpenTable(CString strTable, 
							  CAdoDatabase* pDatabase)
{
	//����Recordset�ӿڶ���
	HRESULT nRet=
		m_pRecordset.CreateInstance(__uuidof(Recordset));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	//�򿪱�
	nRet=m_pRecordset->Open(
		_variant_t(strTable),
		(IDispatch*)pDatabase->m_pConn,
		adOpenKeyset,
		adLockOptimistic,
		adCmdTable);
	if (FAILED(nRet))
	{
		m_pRecordset.Release();//����IUnknown::Release
		return FALSE;
	}
	return TRUE;
		
}
BOOL CAdoRecordset::OpenSql(CString strSql,CAdoDatabase* pDatabase)
{
	//����Recordset�ӿڶ���
	HRESULT nRet=
		m_pRecordset.CreateInstance(__uuidof(Recordset));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	//�򿪱�
	nRet=m_pRecordset->Open(
		_variant_t(strSql),
		(IDispatch*)pDatabase->m_pConn,
		adOpenKeyset,
		adLockOptimistic,
		adCmdText);
	if (FAILED(nRet))
	{
		m_pRecordset.Release();//����IUnknown::Release
		return FALSE;
	}
	return TRUE;
}
UINT CAdoRecordset::GetFieldsCount()
{
	if (m_pRecordset)
	{
		return m_pRecordset->Fields->GetCount();
	}
	return 0;
}
CString CAdoRecordset::GetFieldName(long nIndex)
{
	if (m_pRecordset)
	{
		CString strName;
		strName=(LPCTSTR)(_bstr_t)
			m_pRecordset->Fields->
			GetItem(_variant_t(nIndex))->GetName();
		return strName;
	}
	return "";
}
void CAdoRecordset::MoveFirst()
{
	if (m_pRecordset)
	{
		if (!m_pRecordset->BOF)//�м�¼ʱ
		{
			m_pRecordset->MoveFirst();
		}
	}
}
void CAdoRecordset::MoveNext()
{
	if (m_pRecordset)
	{
		m_pRecordset->MoveNext();
	}
}
void CAdoRecordset::MoveLast()
{
	if (m_pRecordset)
	{
		m_pRecordset->MoveLast();
	}
}
void CAdoRecordset::MovePrevious()
{
	if (m_pRecordset)
	{
		m_pRecordset->MovePrevious();
	}
}
void CAdoRecordset::Move(LONG nIndex)
{
	if (m_pRecordset)
	{
		m_pRecordset->Move(nIndex,
			_variant_t((LONG)adBookmarkFirst));
	}
}
BOOL CAdoRecordset::IsEOF()
{
   if (m_pRecordset)
   {
	   return m_pRecordset->EndEOF;
   }
   return TRUE;
}
BOOL CAdoRecordset::GetValue(LONG nIndex,
							 CString & strValue)
{
	if (m_pRecordset)
	{
		if(m_pRecordset->Fields->
		   GetItem(_variant_t(nIndex))->Value.vt!=VT_NULL)//�ж����ݲ�Ϊ��
		{
		   strValue=(LPCTSTR)(_bstr_t)
		   m_pRecordset->Fields->
		   GetItem(_variant_t(nIndex))->Value;
		}
	   return TRUE;
	}
	return FALSE;
}
BOOL CAdoRecordset::SetValue(LONG nIndex,CString strValue)
{
   if (m_pRecordset)
   {
	   m_pRecordset->Fields->
		   GetItem(_variant_t(nIndex))->Value=
		   _bstr_t(strValue);
	   return TRUE;
   }
   return FALSE;
}
BOOL CAdoRecordset::AddNew()
{
	if (m_pRecordset)
	{
		m_pRecordset->AddNew();
		return TRUE;
	}
	return FALSE;
}
BOOL CAdoRecordset::Delete()
{
	if (m_pRecordset)
	{
		m_pRecordset->Delete(adAffectCurrent);
		return TRUE;
	}
	return FALSE;
}
void CAdoRecordset::Update()
{
	if (m_pRecordset)
	{
		m_pRecordset->Update();
	}
}
BOOL CAdoRecordset::SetBinaryValue(LONG nIndex,
						BYTE* pData, ULONG nLen)
{
   //��������
	SAFEARRAYBOUND bound={0};
	bound.cElements=nLen;
	bound.lLbound=0;
	SAFEARRAY* pArray=SafeArrayCreate(VT_UI1,1,&bound);
	//�����ݷ��밲ȫ������
	for (LONG Index=0;Index<nLen;Index++)
	{
		SafeArrayPutElement(pArray,&Index,pData+Index);
	}
	//�������
	VARIANT varChunk={0};
	varChunk.vt=VT_ARRAY|VT_UI1;
	varChunk.parray=pArray;
    //���ýӿں����������ݱ��浽���ݿ���
	m_pRecordset->Fields->GetItem(_variant_t(nIndex))
		->AppendChunk(&varChunk);
	//������ͷ�
	SafeArrayDestroy(pArray);
	return TRUE;

}
BOOL CAdoRecordset::GetBinaryValue(LONG nIndex,
					BYTE* pData, ULONG & nLen)
{
	//��ȡ���ݵĳ���
	LONG nActualSize=m_pRecordset->Fields->GetItem(
		_variant_t(nIndex))->ActualSize;
    if (pData==NULL)
    {
       nLen=nActualSize;
       return TRUE;
    }
	//��ȡ����
	if (nActualSize>nLen)//BUFF�ռ䲻��
	{
		nLen=nActualSize;
		return FALSE;
	}
	//�����ݿ��ȡ���ݣ����浽varValue������
	_variant_t varValue=m_pRecordset->Fields->GetItem(
		_variant_t(nIndex))->GetChunk(nLen);
	//��varValue��ֵ���浽pDataָ���BUFF��
	for (LONG index=0;index<nLen;index++)
	{
		SafeArrayGetElement(varValue.parray,
			&index,pData+index);
	}
	return TRUE;
    

}