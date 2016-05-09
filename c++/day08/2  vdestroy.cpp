#include <iostream>
using namespace std;
class Parent{
public:
	Parent(){cout << "Parent()" << endl;}
	virtual ~Parent(){cout<<"~Parent()"<<endl;}//析构函数运行期绑定，在运行期决定调用哪个函数,虚函数的调用取决于虚函数列表，不取决于编译器
	virtual void show(){}
};
class Child : public Parent{
public:
	Child(){cout << "Child()" << endl;}
	virtual ~Child(){cout << "~Child()" << endl;}
};
int main()
{
	Parent* p = new Child;
	delete p;
}

/*虚析构
	如果类是支持多态的,那么析构函数应该上虚函数.*/
