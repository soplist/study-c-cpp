#include <iostream>
using namespace std;
//父类,基类
class Parent{
	private: int i1;//成员变量也可以是公开，保护，私有的
	protected: int i2;
	public: int i3;
};
//子类,派生类
class Child1 : public Parent{//公开的继承
public:
	void show(){
		//i1++;//父类里面私有的在子类里不能访问
		i2++;//只能在类的内部和子类的内部访问
		i3++;
	}
};

class Child2 : private Parent{//私有的继承，是悄悄的继承，在类的外部完全不能访问
public:
	void show(){
		//i1++;
		i2++;
		i3++;
	}	
};

class Child3 : protected Parent{//保护的继承
public:
	void show(){
		//i1++;
		i2++;
		i3++;
	}
};

int main()
{
	Parent p;
	//p.i1 = 10;//私有的，只能在类的内部访问
	//p.i2 = 20;//保护的，只能在类的内部和子类的内部访问
	p.i3 = 30;		
	Child1 c1;
	//c1.i1 = 10;
	//c1.i2 = 20;
	c1.i3 = 30;	
	Child2 c2;
	//c2.i1 = 10;
	//c2.i2 = 20;
	//c2.i3 = 30;//私有的继承，在类的外部不能访问
	Child3 c3;
	//c3.i1 = 10;
	//c3.i2 = 20;
	//c3.i3 = 30;保护的成员对于类的外部来说是私有的.
}

