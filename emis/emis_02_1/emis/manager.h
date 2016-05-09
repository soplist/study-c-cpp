#ifndef _MANAGER_H
#define _MANAGER_H
#include <string>
using namespace std;
namespace emis{
class Manager{
public:
		 Manager(void);
		 Manager(int);//提供空参构造和id构造
		 int getId(void);//后期自动生成
		 string getName();
		 void setName(const char* name);
		 string getPassword();
		 void setPassword(const char* password);
private:
		 int m_id;
		 char m_name[20];//manager以二进制保存,如果是string类型，则保存的是指针
		 char m_password[20];
};
}
#endif
