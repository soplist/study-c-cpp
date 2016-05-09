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
}//����UI��ҵ���߼�
ManagerViewConsoleImpl::~ManagerViewConsoleImpl(void){
			delete m_service;
}
	//��ʾ�˵�
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
			case 0: cout << "ллʹ��!" <<endl;
					  return ;
			default:cout<<endl<<"ѡ�����!"<<endl;
					  break;
		}
	}
}
void ManagerViewConsoleImpl::add(){
		 Manager manager;
		 cout << "���������Ա����:"<<flush;
		 char buf[20];
		 cin >> buf;
		 manager.setName(buf);
		 cout << "���������Ա����:"<< flush;
		 cin >> buf;
		 manager.setPassword(buf);
		 if(m_service->addManager(manager)){
		 		cout << "��ӳɹ�!!" << endl;
		 }else
					cout << "���ʧ��!"<<endl;
}
void ManagerViewConsoleImpl::del(){
	cout << "���������ԱID:" << flush;
	int id;
	cin >> id;
	if(!m_service->delManager(id)){
			cout<<"����ԱID��Ч!û�и�ID"<<endl;
			cin.clear();//����һ��������״̬.��֤��һ����������
			cin.ignore(1024,'\n');//���ԷǷ��ַ�
				//���������ĺ���:���Ե�1024���ַ���������������'\n'ʱ����,����ͨ���ѵ�һ������������㹻�󣬶�ʹ'\n'��Ч������һ��.
	}else 
		  cout << "ɾ������Ա�ɹ�!" << endl;
}
void ManagerViewConsoleImpl::list(){
	  const vector<Manager>& managers = 
				 m_service->listManager();
	  cout << endl << left << setw(11) 
			<< "����ԱID " << setw(22) <<
			"����Ա�û��� "  << "����Ա����" 
			<< endl;
	  cout<<"------------------------------------------" <<endl;
	  //�������manager����Ϣ
		for(vector<Manager>::const_iterator it=
	managers.begin();it!=managers.end();it++){
		cout << setw(11) << it->getId() <<
				  setw(22) << it->getName()<<
				  it->getPassword() << endl;
		}
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
		//cout << nEnter;
		return nEnter;
	}
		return -1;//�Ƿ�����-1
} 
}
