#ifndef _MANAGERVIEW_CONSOLE_IMPL_H
#define _MANAGERVIEW_CONSOLE_IMPL_H
#include "managerview.h"
/*������ϵͳUI����ӿ�*/
namespace emis{
class ManagerViewConsoleImpl:public ManagerView{
public:
	ManagerViewConsoleImpl(void);
	~ManagerViewConsoleImpl(void);
	//��ʾ�˵�
	void menu();//���Ǵ��麯��
	void add();
	void del();
	void list();
private:
	int showMenu(void);//�ṩ˽�к���������ʾ�˵�
};
}
#endif 
