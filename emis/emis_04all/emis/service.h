#ifndef _SERVICE_H
#define _SERVICE_H
#include <vector>
using namespace std;
#include "department.h"
namespace emis{
class Service{
public:
	virtual ~Service(){}
	virtual bool addDept(const Department& dept) = 0;
	virtual bool deleteDept(int id) = 0;
	virtual const vector<Department>& listDept() = 0;
	virtual bool addEmp(int id,const Employee& employee) = 0; //��Ӳ����µ�Ա��
	virtual bool deleteEmp(int id) = 0;
	virtual bool modifyEmp(const Employee& employee) = 0;
	virtual vector<Employee>& listEmp(int id) = 0;//���ز���ά������������
	virtual vector<Employee> listAllEmp(void) = 0;
};
}
#endif

