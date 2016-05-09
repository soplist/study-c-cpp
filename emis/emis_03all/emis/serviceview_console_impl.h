#ifndef _SERVICEVIEW_CONSOLE_IMPL_H
#define _SERVICEVIEW_CONSOLE_IMPL_H
#include "serviceview.h"
namespace emis{
class ServiceViewConsoleImpl : public 
		ServiceView{
public:
		ServiceViewConsoleImpl(void);
		~ServiceViewConsoleImpl(void);
		void menu(void);
		void addDept(void);
		void deleteDept(void);
		void listDept(void);
		void addEmp(void);
		void deleteEmp(void);
		void modifyEmp(void);
		void listEmp(void);
		void listAllEmp(void);
private:
		int showMenu(void);//同样提供私有的函数来显示主菜单
};
}
#endif
