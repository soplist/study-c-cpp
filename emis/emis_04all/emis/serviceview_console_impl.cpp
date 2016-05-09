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
						cout << "ѡ�����!" <<endl;
				break;
				}
		}
}
void ServiceViewConsoleImpl::addDept(void){
		Department dept;//�޲�
		cout << "���벿������:" << flush;
		cin >> dept.m_name;
		
		if(!m_service->addDept(dept))
			cout << "��Ӳ���ʧ��!" <<endl;
		 else 
			cout << "���Ӳ��ųɹ�!" << endl;
}

void ServiceViewConsoleImpl::deleteDept(void){
	cout << "���벿��ID :" << flush;
	int id = -1;
	cin >> id;
	if(!m_service->deleteDept(id)){
			cout << "��Ч�Ĳ���ID" << endl;
			cin.clear();
			cin.ignore(1024,'\n');
	}else
		cout << "ɾ���ɹ�!" << endl;
}
void ServiceViewConsoleImpl::listDept(void){
	 const vector<Department>& depts = m_service->listDept();
	 cout << endl<<left <<setw(11) << "����ID"
	 << setw(22) << "��������" << "����Ա������" << endl;
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
