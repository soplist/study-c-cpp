#ifndef _MANAGERVIEW_H
#define _MANAGERVIEW_H
/*管理子系统UI界面接口*/
namespace emis{
class ManagerView{
public:
	virtual ~ManagerView(){}
	//显示菜单
	virtual void menu() = 0;
	virtual void add() = 0;
	virtual void del() = 0;
	virtual void list() = 0;
};
}
#endif //_MANAGERVIEW_H
