#ifndef _MANAGERVIEW_H
#define _MANAGERVIEW_H
/*������ϵͳUI����ӿ�*/
namespace emis{
class ManagerView{
public:
	virtual ~ManagerView(){}
	//��ʾ�˵�
	virtual void menu() = 0;
	virtual void add() = 0;
	virtual void del() = 0;
	virtual void list() = 0;
};
}
#endif //_MANAGERVIEW_H
