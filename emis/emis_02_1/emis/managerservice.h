#ifndef _MANAGERSERVICE_H
#define _MANAGERSERVICE_H
#include <vector>
#include "manager.h"
using namespace std;
namespace emis{
class ManagerService{
public:
		virtual ~ManagerService(void){}
		virtual bool addManager(const Manager& manager) = 0;
		virtual bool delManager(int id) = 0;
		virtual vector<Manager>& listManager(void) = 0; //返回一个容器的引用  
};
}
#endif // _MANAGERSERVICE_H

