#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
#include <iostream>
#include <vector>
using namespace std;
#include "employee.h"
namespace emis{
/*������*/
class Department{
public:
	Department(void);
	Department(int nId);

	bool deleteEmp(int empId);
	void listEmp(vector<Employee>& Emps);
	bool modifyEmp(const Employee& emp);	
	
	friend istream& operator>>(istream& is, Department& dept);
	friend ostream& operator<<(ostream& os,const Department& dept); 

	int m_id;//����id
	string m_name;// ��������	
	vector<Employee> m_Emps;//Ա��
};
}
#endif // _DEPTMENT_H

