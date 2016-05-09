#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Time{
	int h;
	int m;
	int s;
public:
	//用默认值减少构造函数的个数(函数的参数是可以有默认值的)
	Time(int a=0, int b=0, int c=0){
		cout<<"Time(int,int,int)"<<endl;
		h = a; m = b; s = c;
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
	Time t;
}
//构造函数的参数也可以有默认值,经常用默认值的方式减少构造函数的个数,比如空参的构造函数经常会用参数有默认值的构造函数替代.
