#include "department.h"
#include "tools.h"
namespace emis{  
/*������*/
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
	//��������ά����Ա���б��ÿһ��Ԫ�ؼ��뵽����������
	for(vector<Employee>::iterator it = m_Emps.begin(); it!= m_Emps.end();it++)
	Emps.push_back(*it);//�ⲿ�Ϳ��Է���Ա���б���
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
		Employee employee(0);//��Ԫ
		is >> employee;//Employee֧��
		dept.m_Emps.push_back(employee);
		//���������е�Ա��д�뵽m_Emps����
	}
	return is;
}
ostream& operator<<(ostream& os,const Department& dept){
	os << dept.m_id << ' '
		 << dept.m_name <<  ' '
		<< dept.m_Emps.size() << endl;
	//��ӡ����Ա��
	for(vector<Employee>::const_iterator it= dept.m_Emps.begin();it!=dept.m_Emps.end();it++)
		os << *it << endl;
	return os;
}
}

