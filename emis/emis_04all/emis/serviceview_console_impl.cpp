#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "serviceview_console_impl.h"
#include "service_impl.h"
namespace emis{
ServiceViewConsoleImpl::ServiceViewConsoleImpl(void){
		this->m_service = new ServiceImpl;
}
ServiceViewConsoleImpl::
	~ServiceViewConsoleImpl(void){
		delete m_service;
	}
void ServiceViewConsoleImpl::menu(void){
		for(;;){
				switch(showMenu()){
					case 1:addDept();break;
					case 2:deleteDept();break;
					case 3:listDept();break;
					case 4:addEmp();break;
					case 5:deleteEmp();break;
					case 6:modifyEmp();break;
				case 7:listEmp();break;
				case 8:listAllEmp();break;
				case 0:return;
				default:
						cout << "选择错误!" <<endl;
				break;
				}
		}
}
void ServiceViewConsoleImpl::addDept(void){
		Department dept;//无参
		cout << "输入部门名称:" << flush;
		cin >> dept.m_name;
		
		if(!m_service->addDept(dept))
			cout << "添加部门失败!" <<endl;
		 else 
			cout << "增加部门成功!" << endl;
}

void ServiceViewConsoleImpl::deleteDept(void){
	cout << "输入部门ID :" << flush;
	int id = -1;
	cin >> id;
	if(!m_service->deleteDept(id)){
			cout << "无效的部门ID" << endl;
			cin.clear();
			cin.ignore(1024,'\n');
	}else
		cout << "删除成功!" << endl;
}
void ServiceViewConsoleImpl::listDept(void){
	 const vector<Department>& depts = m_service->listDept();
	 cout << endl<<left <<setw(11) << "部门ID"
	 << setw(22) << "部门名称" << "部门员工人数" << endl;
	cout <<"-----------------------------" << endl;
	for(vector<Department>::const_iterator it=
depts.begin();it!=depts.end();it++)
	 cout << endl<<left <<setw(11) << it->m_id
	 << setw(22) << it->m_name << it->m_Emps.size() << endl;
}
//TODO
void ServiceViewConsoleImpl::addEmp(void){
}
void ServiceViewConsoleImpl::deleteEmp(void){}
void ServiceViewConsoleImpl::modifyEmp(void){}
void ServiceViewConsoleImpl::listEmp(void){}
void ServiceViewConsoleImpl::listAllEmp(void){
}
int ServiceViewConsoleImpl::showMenu(void){//显示主菜单
    cout << endl;
	 cout << "运营管理子系统" << endl;
	 cout << "----------------" << endl;
	 cout << "[1] 增加部门" << endl;
	 cout << "[2] 删除部门" << endl;
	 cout << "[3] 列出部门" << endl;
	 cout << "[4] 增加员工" << endl;
	 cout << "[5] 删除员工" << endl;
	 cout << "[6] 修改员工" << endl;
	 cout << "[7] 列出部门员工" << endl;
	 cout << "[8] 列出所有员工" << endl;
	 cout << "[0] 返回" << endl;
	 cout << "-----------------" << endl;
	 cout << "请选择:" << flush;
	 cin.clear();
	 string strEnter;
	 cin >> strEnter;
	 if(strspn(strEnter.c_str(),"012345678")==strEnter.length()){
	 		istringstream iss(strEnter);
			int nEnter;
			iss >> nEnter;
			return nEnter;
	 }
	 return -1;
}
}
