#include "employee.h"
#include "tools.h"
namespace emis{

Employee::Employee(void):m_id(generator_id()){ //自动生成id
}
Employee::Employee(int nId){
}
//友元函数实现 全局函数不用加::
istream& operator>> (istream& is, Employee& emp){
	//写入	
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

