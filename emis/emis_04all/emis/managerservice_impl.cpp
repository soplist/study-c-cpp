#include "managerservice_impl.h"
#include "managerdao_file_impl.h"
namespace emis{
ManagerServiceImpl::ManagerServiceImpl(void):m_dao(new ManagerDaoFileImpl){
		m_dao->load(m_managers);//下载,反序列化
}
ManagerServiceImpl::~ManagerServiceImpl(void){
		m_dao -> save(m_managers);
		delete m_dao;
}

bool ManagerServiceImpl::addManager(const Manager& manager){
		//往我的容器中添加manager
		m_managers.push_back(manager);
		return true;//todo 暂不考虑失败的情况
}
bool ManagerServiceImpl::delManager(int id){
		//利用迭代器遍历容器中的manager 看有没有和id匹配的
		for(vector<Manager>::iterator it =
		 m_managers.begin(); it!=m_managers.end();it++){
				if(it->getId() == id){
				//从容器中删除,参数it
					m_managers.erase(it);
					return true;
				}
		}
			return false;
}
vector<Manager>& ManagerServiceImpl::listManager(void){
		return m_managers;//直接返回自身维护的管理员容器
}
}
