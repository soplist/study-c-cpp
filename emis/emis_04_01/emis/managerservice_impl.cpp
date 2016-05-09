#include "managerservice_impl.h"
#include "managerdao_file_impl.h"
namespace emis{
ManagerServiceImpl::ManagerServiceImpl(void):m_dao(new ManagerDaoFileImpl){
		m_dao->load(m_managers);//����,�����л�
}
ManagerServiceImpl::~ManagerServiceImpl(void){
		m_dao -> save(m_managers);
		delete m_dao;
}

bool ManagerServiceImpl::addManager(const Manager& manager){
		//���ҵ����������manager
		m_managers.push_back(manager);
		return true;//todo �ݲ�����ʧ�ܵ����
}
bool ManagerServiceImpl::delManager(int id){
		//���õ��������������е�manager ����û�к�idƥ���
		for(vector<Manager>::iterator it =
		 m_managers.begin(); it!=m_managers.end();it++){
				if(it->getId() == id){
				//��������ɾ��,����it
					m_managers.erase(it);
					return true;
				}
		}
			return false;
}
vector<Manager>& ManagerServiceImpl::listManager(void){
		return m_managers;//ֱ�ӷ�������ά���Ĺ���Ա����
}
}
