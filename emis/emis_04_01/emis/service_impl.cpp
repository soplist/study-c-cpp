#include "service_impl.h"
namespace emis{
ServiceImpl::ServiceImpl(void){
}
ServiceImpl::~ServiceImpl(){
}
bool ServiceImpl::addDept(const Department& dept){
		//��Ӳ���
		m_depts.push_back(dept);
		return true;//д�ɹ̶�ֵ
}
bool ServiceImpl::deleteDept(int id){
		//m_depts���� 
	for(vector<Department>::iterator
	it = m_depts.begin(); it!=m_depts.end();it++)
		if(it->m_id == id){
			 m_depts.erase(it);
			 return true;	
		}
	return false;
}
const vector<Department>& ServiceImpl::listDept(){
		return m_depts;
}
bool ServiceImpl::addEmp(int id,const Employee& employee){ //��Ӳ����µ�Ա��
	//������û���������,
	for(vector<Department>::iterator
	it = m_depts.begin(); it!=m_depts.end();it++)
		if(it->m_id == id){
		it->m_Emps.push_back(employee);
		return true;
		}
	return false;
}
bool ServiceImpl::deleteEmp(int id){
	  
}
bool ServiceImpl::modifyEmp(const Employee& employee){
}
vector<Employee>& ServiceImpl::listEmp(int id){//���ز���ά������������
}
vector<Employee> ServiceImpl::listAllEmp(void){
}
}

