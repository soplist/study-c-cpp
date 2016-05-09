#include <iostream>
using namespace std;

class Sample{
	int x;
	mutable int y;
public:
	Sample(int x=0):x(x){}
	void setX(int x){this->x = x;}//修改x用
	//只读函数
	int getX()const{return x;}	//读取x
	void show()const{cout<<"x="<<x<<endl;}//加const是为了告诉编译器，我这个函数不修改成员变量，这样编译器才让你调用
	void show(){cout<<"##x="<<x<<endl;}
	//只读函数可以修改mutable的成员变量
	void setY(int y)const{ this->y=y; }
};

int main()
{
	Sample s;
	s.show();
	//s.setX(100);
	s.show();
	cout << s.getX() << endl;
}

/*4.只读对象const
	4.1 对只读对象只能调用只读函数,不能调用非只读函数.对于非只读对象,即可以调用非只读函数,也可以调用只读函数.
	4.2 如果一个类的成员函数不会修改成员变量的值,那么,就把他(成员函数)声明成只读函数.
	4.3 只读和非只读函数可以形成重载关系.此时,对于只读对象,只能调用只读函数,而非只读对象会优先选择非只读函数.
	4.4 特殊情况:
		只读函数可以修改声明为mutable的成员变量.*/
