#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Time{
	int h;
	int m;
	int s;
public:
	//��Ĭ��ֵ���ٹ��캯���ĸ���(�����Ĳ����ǿ�����Ĭ��ֵ��)
	Time(int a=0, int b=0, int c=0){
		cout<<"Time(int,int,int)"<<endl;
		h = a; m = b; s = c;
	}	
	//��1��
	void dida(){
		s++;
		if(s==60){ s=0; m++; }	
		if(m==60){ m=0; h++; }
		if(h==24){ h=0;}
	}
	//��ʾʱ��
	void show(){
		cout<<setfill('0');
		cout<<setw(2)<<h<<":"<<setw(2)
		<<m<<":"<<setw(2)<<s<<flush<<"\r";
	}
	//����,ÿ��1��,��ʾһ��
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
//���캯���Ĳ���Ҳ������Ĭ��ֵ,������Ĭ��ֵ�ķ�ʽ���ٹ��캯���ĸ���,����ղεĹ��캯���������ò�����Ĭ��ֵ�Ĺ��캯�����.
