#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
namespace emis{
/*������*/
class DepartMent{
public:
	DepartMent(void);
	DepartMent(int nId);

	bool deleteEmp(int empId);
	void listEmp(vector<Empoyee>& Emps);
	bool modifyEmp(Employee& emp);	
	
	friend istream& operator>>(istream& is, DepartMent& dept);
	friend ostream& operator<<(ostream& os,const DepartMent& dept);

	int m_id;//����id
	string m_strName;// ��������	
	vector<Employee> m_Emps;//Ա��
};
}
#endif // _DEPTMENT_H

