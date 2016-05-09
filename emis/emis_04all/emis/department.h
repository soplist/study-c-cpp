#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
#include <iostream>
#include <vector>
using namespace std;
#include "employee.h"
namespace emis{
/*部门类*/
class Department{
public:
	Department(void);
	Department(int nId);

	bool deleteEmp(int empId);
	void listEmp(vector<Employee>& Emps);
	bool modifyEmp(const Employee& emp);	
	
	friend istream& operator>>(istream& is, Department& dept);
	friend ostream& operator<<(ostream& os,const Department& dept); 

	int m_id;//部门id
	string m_name;// 部门名称	
	vector<Employee> m_Emps;//员工
};
}
#endif // _DEPTMENT_H

