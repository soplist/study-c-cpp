#include "managerview_console_impl.h"
#include <iostream>
#include <iomanip> //setw
#include <cstring>
#include <sstream> //istringstream 
#include "managerservice_impl.h"
#include "serviceview_console_impl.h"
using namespace std;
namespace emis{
ManagerViewConsoleImpl::ManagerViewConsoleImpl(void):m_service(new ManagerServiceImpl){
}//整合UI和业务逻辑
ManagerViewConsoleImpl::~ManagerViewConsoleImpl(void){
			delete m_service;
}
	//显示菜单
void ManagerViewConsoleImpl::menu(){
	for(;;){
		switch(showMenu()){
			case 1: add();break;
			case 2: del();break;
			case 3: list();break;
			case 4: {
	ServiceView* pView = new ServiceViewConsoleImpl;
	pView->menu();	
	delete pView;		
					  break;
					}
			case 0: cout << "谢谢使用!" <<endl;
					  return ;
			default:cout<<endl<<"选择错误!"<<endl;
					  break;
		}
	}
}
void ManagerViewConsoleImpl::add(){
		 Manager manager;
		 cout << "请输入管理员姓名:"<<flush;
		 char buf[20];
		 cin >> buf;
		 manager.setName(buf);
		 cout << "请输入管理员密码:"<< flush;
		 cin >> buf;
		 manager.setPassword(buf);
		 if(m_service->addManager(manager)){
		 		cout << "添加成功!!" << endl;
		 }else
					cout << "添加失败!"<<endl;
}
void ManagerViewConsoleImpl::del(){
	cout << "请输入管理员ID:" << flush;
	int id;
	cin >> id;
	if(!m_service->delManager(id)){
			cout<<"管理员ID无效!没有该ID"<<endl;
			cin.clear();//清理一下输入流状态.保证下一次正常输入
			cin.ignore(1024,'\n');//忽略非法字符
				//两个参数的含义:忽略掉1024个字符结束，或者遇到'\n'时结束,我们通常把第一个参数定义的足够大，而使'\n'生效，忽略一行.
	}else 
		  cout << "删除管理员成功!" << endl;
}
void ManagerViewConsoleImpl::list(){
	  const vector<Manager>& managers = 
				 m_service->listManager();
	  cout << endl << left << setw(11) 
			<< "管理员ID " << setw(22) <<
			"管理员用户名 "  << "管理员密码" 
			<< endl;
	  cout<<"------------------------------------------" <<endl;
	  //遍历输出manager的信息
		for(vector<Manager>::const_iterator it=
	managers.begin();it!=managers.end();it++){
		cout << setw(11) << it->getId() <<
				  setw(22) << it->getName()<<
				  it->getPassword() << endl;
		}
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
		//cout << nEnter;
		return nEnter;
	}
		return -1;//非法返回-1
} 
}
