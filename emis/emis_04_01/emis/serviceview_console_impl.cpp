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
						cout << "ѡ�����!" <<endl;
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
int ServiceViewConsoleImpl::showMenu(void){//��ʾ���˵�
    cout << endl;
	 cout << "��Ӫ������ϵͳ" << endl;
	 cout << "----------------" << endl;
	 cout << "[1] ���Ӳ���" << endl;
	 cout << "[2] ɾ������" << endl;
	 cout << "[3] �г�����" << endl;
	 cout << "[4] ����Ա��" << endl;
	 cout << "[5] ɾ��Ա��" << endl;
	 cout << "[6] �޸�Ա��" << endl;
	 cout << "[7] �г�����Ա��" << endl;
	 cout << "[8] �г�����Ա��" << endl;
	 cout << "[0] ����" << endl;
	 cout << "-----------------" << endl;
	 cout << "��ѡ��:" << flush;
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
