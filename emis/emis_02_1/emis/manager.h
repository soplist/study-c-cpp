#ifndef _MANAGER_H
#define _MANAGER_H
#include <string>
using namespace std;
namespace emis{
class Manager{
public:
		 Manager(void);
		 Manager(int);//�ṩ�ղι����id����
		 int getId(void);//�����Զ�����
		 string getName();
		 void setName(const char* name);
		 string getPassword();
		 void setPassword(const char* password);
private:
		 int m_id;
		 char m_name[20];//manager�Զ����Ʊ���,�����string���ͣ��򱣴����ָ��
		 char m_password[20];
};
}
#endif
