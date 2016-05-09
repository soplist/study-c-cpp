#include <iostream>
using namespace std;
#include "serviceview_console_impl.h"
namespace emis{
ServiceViewConsoleImpl::ServiceViewConsoleImpl(void){
}
ServiceViewConsoleImpl::
	~ServiceViewConsoleImpl(void){
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
}
void ServiceViewConsoleImpl::deleteDept(void){
}
void ServiceViewConsoleImpl::listDept(void){
}
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
