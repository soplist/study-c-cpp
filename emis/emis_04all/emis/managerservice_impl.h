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
		vector<Manager> m_managers;//manager����,�����г�����Ա
		ManagerDao* m_dao;//dao�ӿ�
};
}
#endif // _MANAGERSERVICE_IMPL_H
