#include <iostream>
#include <ctime>
#include <iomanip>//输出格式的控制头文件
using namespace std;
class Time{
public:
	int h;
	int m;
	int s;
	//走1秒
	void dida(){
		s++;
		if(s==60){ s=0; m++; }	
		if(m==60){ m=0; h++; }
		if(h==24){ h=0;}
	}
	//显示时间
	void show(){
		cout<<setfill('0');//意思是说用0来填充空白位置
		cout<<setw(2)<<h<<":"<<setw(2)
		<<m<<":"<<setw(2)<<s<<flush<<"\r";//setw(2),意思是用俩个位置输出这个数。flush，刷新缓冲区， ""\r" 不换行
	}
	//运行,每走1秒,显示一次
	void run(){
		while(1){//表示不停的走，死循环
			show();
			dida();
			time_t cur = time(0);//time(0)表示当前时间
			while(time(0)==cur);		
		}
	}
};
int main()
{
	Time t;
	t.h=0; t.m=0; t.s=0;
	t.run();
}

