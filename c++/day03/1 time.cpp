#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Time{
	int h;
	int m;
	int s;
public:
/*   用普通函数初始化成员变量
	void set(int a, int b, int c){
		h = a; m = b; s = c;
	}
*/
	//构造函数 初始化成员变量，参数列表可以没有
	Time(int a, int b, int c){
		cout<<"Time(int,int,int)"<<endl;
		h = a; m = b; s = c;
	}	
	//空参构造
	Time(){
		cout << "Time()" << endl;
		h = m = s = 0;
	}
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
	Time t(0, 0, 0);//定义一个变量，就相当于构造一个对象，传三个参数是为了调用自己写的构造函数
//      Time t;  调用默认的空参构造函数
	//t.h=0; t.m=0; t.s=0;
	//t.run();
	Time t2(23,59,55);
//	t2.run();
	Time t3; 
	t3.run();//调用空参构造函数
}

//成员变量通常是私有的，成员函数一般是公开的（函数的声明是公开的，函数的实现是隐藏的）
//一个类里面可以有多个构造函数，构造函数也是函数，具有函数的特征，可以重载，至于具体调用哪个就看你传几个参数了
