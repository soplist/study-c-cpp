#include <iostream>
using namespace std;

class Sample{
	int x;
	mutable int y;
public:
	Sample(int x=0):x(x){}
	void setX(int x){this->x = x;}
	int getX()const{return x;}	
	void show()const{cout<<"x="<<x<<endl;}
	void show(){cout<<"##x="<<x<<endl;}
	void setY(int y)const{ this->y=y; }
};

void fa(Sample s){ s.show(); }
void fb(Sample& s){ s.setX(200); }
void fc(const Sample& s){
	//s.setX(300);//不能调用非只读函数
	s.show();
}
//实际开发中,很少见如下参数
void fd(const Sample s){ }
int main()
{
	Sample s(100);
	fa(s);//值传递
	fb(s);
	s.show();	
	fc(s);//非只读对象传给只读引用
	const Sample s2;//s2是个只读的对象
	fc(s2);
//	fb(s2);//不能将只读对象传给非只读引用
}

