#ifndef _MANAGERSERVICE_IMPL_H
#define _MANAGERSERVICE_IMPL_H
#include "managerservice.h"
#include "managerdao.h"
namespace emis{
class ManagerServiceImpl:public ManagerService{
public:
		ManagerServiceImpl(void);
		~ManagerServiceImpl(void);
		bool addManager(const Manager& manager);
	   bool delManager(int id);
      vector<Manager>& listManager(void); 
private:
		vector<Manager> m_managers;//manager容器,用来列出管理员
		ManagerDao* m_dao;//dao接口
};
}
#endif // _MANAGERSERVICE_IMPL_H
