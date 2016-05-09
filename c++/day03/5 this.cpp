#include <iostream>
#include <cstdio>
using namespace std;
class Time{
	int hour;
	int min;
	int sec;
public:
	Time(int h=0,int m=0,int s=0)
	:hour(h),min(m),sec(s){
		cout<<"Time(int,int,int)"<<endl;
	}
	void setHour(int hour){// hour 是局部变量 ，变量自己给自己赋值是可以的
		this->hour = hour;//局部优先    this->hour 等同于（*this).hour 意思是当前对象的hour,因为调用函数时会把当前对象的地址传给函数，保存在函数的this指针中即&hour=this ,所以*this＝hour
	}
	void setMin(int min){
		this->min = min;	
	}
	void setSec(int sec){
		this->sec = sec;
	}
	Time& dida(){
		sec++;
		if(sec==60){sec=0;min++;}
		if(min==60){min=0;hour++;}
		if(hour==24){hour=0;}
		return *this;//返回当前对象本身	
	}
	string toString(){
		cout << this << endl;
		char buf[12] = {};
		sprintf(buf,"%02d:%02d:%02d",
			this->hour,this->min,this->sec);
		return buf;
	}
};
int main()
{
	Time t;
	cout << t.toString() << endl;
	cout << &t << endl;
	cout << sizeof(t) << endl;
	cout << sizeof(Time) << endl;
	Time t2(12,58,57);
	cout << t2.toString() << endl;
	cout << &t2 << endl;
	t.setHour(12);
	cout << t.toString() << endl;
	cout << "-------------------" << endl;
	Time t3(16,9,8);
	Time& r3 = t3.dida();//Time& r3=t3;
	cout << r3.toString() << endl;
	cout << t3.dida().dida()
		.dida().dida().toString() << endl;	
}
//对象 在内存中只给成员变量分配空间（栈区）不给成员函数分配空间，成员函数在在代码区，当我们调用某一个对象的函数时，就直接通过这个对象，判断这个对象的类型，找到这个函数然后调用，函数就一个，作为函数，只要知道一件事是哪个对象t.toString==>toString(&t),所以这个函数就通过这个地址知道是哪个对象的h,m,s，这个函数里面有一个this指针，用来接收这个地址
