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
	bool addEmp(int id,const Employee& employee); //添加部门下的员工
	bool deleteEmp(int id);
	bool modifyEmp(const Employee& employee);
	vector<Employee>& listEmp(int id);//返回部门维护容器的引用
	vector<Employee> listAllEmp(void);
private:
	vector<Department> m_depts;//用业务逻辑实现对部门的管理 员工是通过dept
};
}
#endif

