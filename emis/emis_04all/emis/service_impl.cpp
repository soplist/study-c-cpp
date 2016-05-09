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
	for(vector<Department>::iterator
	it = m_depts.begin(); it!=m_depts.end();it++)
	 	if(it->deleteEmp(id))
			return true;
		return false;  
}
bool ServiceImpl::modifyEmp(const Employee& employee){
	for(vector<Department>::iterator
	it = m_depts.begin(); it!=m_depts.end();it++)
	 	if(it->modifyEmp(employee))//����dept��modifyEmp
			return true;
		return false;  
}
vector<Employee>& ServiceImpl::listEmp(int id){//���ز���ά������������
	for(vector<Department>::iterator
	it = m_depts.begin(); it!=m_depts.end();it++)
	 	if(it->m_id == id)
			return it->m_Emps;//����Ա���б�  
		throw -1; //û�в����׳��쳣
}
vector<Employee> ServiceImpl::listAllEmp(void){
 	    vector<Employee> employees;
	for(vector<Department>::iterator
	it = m_depts.begin(); it!=m_depts.end();it++)
		it->listEmp(employees);
		return employees; 
}
}

