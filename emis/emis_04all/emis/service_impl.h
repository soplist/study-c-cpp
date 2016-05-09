#ifndef _SERVICE_IMPL_H
#define _SERVICE_IMPL_H
#include "service.h"
namespace emis{
class ServiceImpl : public Service{
public:
	ServiceImpl(void);
	~ServiceImpl();
	bool addDept(const Department& dept);
	bool deleteDept(int id);
	const vector<Department>& listDept();
	bool addEmp(int id,const Employee& employee); //��Ӳ����µ�Ա��
	bool deleteEmp(int id);
	bool modifyEmp(const Employee& employee);
	vector<Employee>& listEmp(int id);//���ز���ά������������
	vector<Employee> listAllEmp(void);
private:
	vector<Department> m_depts;//��ҵ���߼�ʵ�ֶԲ��ŵĹ��� Ա����ͨ��dept
};
}
#endif

