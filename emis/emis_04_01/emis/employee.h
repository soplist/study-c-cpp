#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;
namespace emis{
class Employee{
/*员工类*/
public:
		Employee(void);
		Employee(int nId);

		friend istream& operator>> (istream& is, Employee& emp);
		friend ostream& operator<< (ostream& os,const Employee& emp);
		//修改成public成员 便于访问
		int m_id;//员工id
		string m_name;//姓名
		bool m_gender;//性别
		int m_age;//年龄
};
}
#endif //_EMPLOYEE_H

