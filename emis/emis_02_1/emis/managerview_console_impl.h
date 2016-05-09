#ifndef _MANAGERVIEW_CONSOLE_IMPL_H
#define _MANAGERVIEW_CONSOLE_IMPL_H
#include "managerview.h"
/*管理子系统UI界面接口*/
namespace emis{
class ManagerViewConsoleImpl:public ManagerView{
public:
	ManagerViewConsoleImpl(void);
	~ManagerViewConsoleImpl(void);
	//显示菜单
	void menu();//覆盖纯虚函数
	void add();
	void del();
	void list();
private:
	int showMenu(void);//提供私有函数用来显示菜单
};
}
#endif 
