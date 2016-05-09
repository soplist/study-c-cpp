#include "service_impl.h"
namespace emis{
ServiceImpl::ServiceImpl(void){
}
ServiceImpl::~ServiceImpl(){
}
bool ServiceImpl::addDept(const Department& dept){
		//添加部门
		m_depts.push_back(dept);
		return true;//写成固定值
}
bool ServiceImpl::deleteDept(int id){
		//m_depts遍历 
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
bool ServiceImpl::addEmp(int id,const Employee& employee){ //添加部门下的员工
	//遍历有没有这个部门,
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
vector<Employee>& ServiceImpl::listEmp(int id){//返回部门维护容器的引用
}
vector<Employee> ServiceImpl::listAllEmp(void){
}
}

