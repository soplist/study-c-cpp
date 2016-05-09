#include "managerview_console_impl.h"
#include <iostream>
#include <cstring>
#include <sstream> //istringstream 
using namespace std;
namespace emis{
ManagerViewConsoleImpl::ManagerViewConsoleImpl(void){
}
ManagerViewConsoleImpl::~ManagerViewConsoleImpl(void){
}
	//显示菜单
void ManagerViewConsoleImpl::menu(){
}
void ManagerViewConsoleImpl::add(){
}
void ManagerViewConsoleImpl::del(){
}
void ManagerViewConsoleImpl::list(){
}
int ManagerViewConsoleImpl::showMenu(){
	cout << endl;
	cout << "企业管理信息系统" <<endl;
	cout << "-------------------"<<endl;
	cout << "[1] 增加管理员"  << endl;
	cout << "[2] 删除管理员" << endl;
	cout << "[3] 列出所有管理员" <<endl;
	cout << "[4] 运营管理" << endl;
	cout << "[0] 退出" << endl;
	cout << "请选择:" << flush;
	//int Enter;
	string strEnter;
	cin >> strEnter;
	//strspn() 返回第一个不符合规则的字符的下标
	if(strspn(strEnter.c_str(),"01234")==strEnter.length()){
		istringstream iss(strEnter);//利用字符串流转成int 
		int nEnter;
		iss >> nEnter;//
		return nEnter;
	}
		return -1;//非法返回-1
} 
}
