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
	void setHour(int hour){// hour �Ǿֲ����� �������Լ����Լ���ֵ�ǿ��Ե�
		this->hour = hour;//�ֲ�����    this->hour ��ͬ�ڣ�*this).hour ��˼�ǵ�ǰ�����hour,��Ϊ���ú���ʱ��ѵ�ǰ����ĵ�ַ���������������ں�����thisָ���м�&hour=this ,����*this��hour
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
		return *this;//���ص�ǰ������	
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
//���� ���ڴ���ֻ����Ա��������ռ䣨ջ����������Ա��������ռ䣬��Ա�������ڴ������������ǵ���ĳһ������ĺ���ʱ����ֱ��ͨ����������ж������������ͣ��ҵ��������Ȼ����ã�������һ������Ϊ������ֻҪ֪��һ�������ĸ�����t.toString==>toString(&t),�������������ͨ�������ַ֪�����ĸ������h,m,s���������������һ��thisָ�룬�������������ַ
