#include <iostream>
using namespace std;
class A{ };
class B{
public:
	operator A(){cout<<"B-->A"<<endl;}//B转换成A
	B(){}//空参构造函数
	//默认情况下,当需要类型转换时,构造函数会被隐式调用而实现类型转换,但当构造函数前加explicit后,此功能就失效
	/*explicit*/
	 B(const A& a){cout<<"A-->B"<<endl;}//A转换成B
};
void fa(A a){cout << "fa" << endl;}
void fb(B b){cout << "fb" << endl;}
int main()
{
	B b;
	A a = b;
	B bb = a;//B bb(a);//默认的调用构造函数的隐式调用
	b = a;//默认的调用构造函数的隐式调用
	fa(a);
	fa(b);
	fb(a);//默认的调用构造函数的隐式调用
	fb(b);
}


