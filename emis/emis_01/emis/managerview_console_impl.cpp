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
	//��ʾ�˵�
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
	cout << "��ҵ������Ϣϵͳ" <<endl;
	cout << "-------------------"<<endl;
	cout << "[1] ���ӹ���Ա"  << endl;
	cout << "[2] ɾ������Ա" << endl;
	cout << "[3] �г����й���Ա" <<endl;
	cout << "[4] ��Ӫ����" << endl;
	cout << "[0] �˳�" << endl;
	cout << "��ѡ��:" << flush;
	//int Enter;
	string strEnter;
	cin >> strEnter;
	//strspn() ���ص�һ�������Ϲ�����ַ����±�
	if(strspn(strEnter.c_str(),"01234")==strEnter.length()){
		istringstream iss(strEnter);//�����ַ�����ת��int 
		int nEnter;
		iss >> nEnter;//
		return nEnter;
	}
		return -1;//�Ƿ�����-1
} 
}
