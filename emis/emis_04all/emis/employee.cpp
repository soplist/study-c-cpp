#include "employee.h"
#include "tools.h"
namespace emis{

Employee::Employee(void):m_id(generator_id()){ //�Զ�����id
}
Employee::Employee(int nId){
}
//��Ԫ����ʵ�� ȫ�ֺ������ü�::
istream& operator>> (istream& is, Employee& emp){
	//д��	
	return is >> emp.m_id 
		 >> emp.m_name >> emp.m_gender
		 >> emp.m_age;
}
ostream& operator<< (ostream& os,const Employee& emp){
return os << emp.m_id 	<< ' ' << 
				emp.m_name  << ' ' << 
				emp.m_gender << ' ' <<
		   	emp.m_age 	<< endl;
}
}

