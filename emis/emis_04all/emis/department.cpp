#include "department.h"
#include "tools.h"
namespace emis{  
/*部门类*/
Department::Department(void){
		this->m_id = generator_id();
}
Department::Department(int nId){
}
bool Department::deleteEmp(int id){
	for(vector<Employee>::iterator it = 
m_Emps.begin(); it!=m_Emps.end();it++){
		if(it->m_id == id)
		{
			m_Emps.erase(it);
			return true;
		}
}
		return false;
}
void Department::listEmp(vector<Employee>& Emps){
	//将部门所维护的员工列表的每一个元素加入到参数容器中
	for(vector<Employee>::iterator it = m_Emps.begin(); it!= m_Emps.end();it++)
	Emps.push_back(*it);//外部就可以访问员工列表了
}
bool Department::modifyEmp(const Employee& emp){
	for(vector<Employee>::iterator it = m_Emps.begin(); it!= m_Emps.end();it++)
   if(it->m_id == emp.m_id){
		it->m_name = emp.m_name;
		it->m_gender = emp.m_gender;
		it->m_age = emp.m_age;
		return true;
	}
	return false; 
}
istream& operator>>(istream& is, Department& dept){
	size_t emps;
	is >> dept.m_id >> dept.m_name 
			>> emps;
	for(size_t i=0; i<emps;i++){
		Employee employee(0);//哑元
		is >> employee;//Employee支持
		dept.m_Emps.push_back(employee);
		//将流中所有的员工写入到m_Emps容器
	}
	return is;
}
ostream& operator<<(ostream& os,const Department& dept){
	os << dept.m_id << ' '
		 << dept.m_name <<  ' '
		<< dept.m_Emps.size() << endl;
	//打印部门员工
	for(vector<Employee>::const_iterator it= dept.m_Emps.begin();it!=dept.m_Emps.end();it++)
		os << *it << endl;
	return os;
}
}

