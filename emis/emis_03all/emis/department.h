#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
namespace emis{
/*部门类*/
class DepartMent{
public:
	DepartMent(void);
	DepartMent(int nId);

	bool deleteEmp(int empId);
	void listEmp(vector<Empoyee>& Emps);
	bool modifyEmp(Employee& emp);	
	
	friend istream& operator>>(istream& is, DepartMent& dept);
	friend ostream& operator<<(ostream& os,const DepartMent& dept);

	int m_id;//部门id
	string m_strName;// 部门名称	
	vector<Employee> m_Emps;//员工
};
}
#endif // _DEPTMENT_H

