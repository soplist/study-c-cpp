#include <iostream>
#include <cstring>
using namespace std;
class A{
public:
	int x;
	virtual void show(){ 
		cout << "in A x=" << x << endl;
	}	
};
class B : public A{
public:
	virtual void show(){
		cout << "in B " << endl;
	}
};
class C : public A{
public:
	virtual void show(){
		cout << "in C " <<endl;
	}
};
int main()
{
	cout << sizeof(A) << endl;
	A* pa = new B;
	A* pb = new C; 
	pa->show();//		
	memcpy(pa, pb, 4);//memcp内存拷贝函数，从pb里面拷贝四个字节到pa里面，让pa指向的对象指向pb指向的对象	
	pa->show();
}

/*多态的实现
虚函数表
	C++通过虚函数表来实现多态.
	如果类有虚函数,那么此类支持多态.此类对象的开始4个字节放的是虚函数表的地址.
	程序运行时,当通过指针或引用调用此对象的虚函数时,先从对象中获取虚函数表,再从表中查要调用的具体函数的地址,最后调用此函数.从而实现多态.
	所以C++中的多态会消耗一些系统时间和资源.如果你的系统对效率要求非常高,可考虑不使用多态.*/
