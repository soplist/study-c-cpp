#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Time{
	int h;
	int m;
	int s;
public:
	//用初始化列表简化构造函数的实现
	Time(int h=0, int m=0, int s=0)
		:h(h),m(m),s(s) { }	//h(h) 括号外面的h是成员变量，里面的h是参数，意思是用参数h初始化成员变量,这个初始化是作分配内存空间时初始化的
	//走1秒
	void dida(){
		s++;
		if(s==60){ s=0; m++; }	
		if(m==60){ m=0; h++; }
		if(h==24){ h=0;}
	}
	//显示时间
	void show(){
		cout<<setfill('0');
		cout<<setw(2)<<h<<":"<<setw(2)
		<<m<<":"<<setw(2)<<s<<flush<<"\r";
	}
	//运行,每走1秒,显示一次
	void run(){
		while(1){
			show();
			dida();
			time_t cur = time(0);
			while(time(0)==cur);		
		}
	}
};
int main()
{
	Time t;
}
/*初始化列表可以简化构造函数的实现.
		初始化列表的初始行为发生在对象分配内存期间,对成员变量的初始化时间比构造函数中早. 好处:
		1)效率会高一点点
		2)对成const成员,引用成员也同样有效.*/
