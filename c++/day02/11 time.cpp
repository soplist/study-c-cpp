#include <iostream>
#include <ctime>
#include <iomanip>//�����ʽ�Ŀ���ͷ�ļ�
using namespace std;
class Time{
public:
	int h;
	int m;
	int s;
	//��1��
	void dida(){
		s++;
		if(s==60){ s=0; m++; }	
		if(m==60){ m=0; h++; }
		if(h==24){ h=0;}
	}
	//��ʾʱ��
	void show(){
		cout<<setfill('0');//��˼��˵��0�����հ�λ��
		cout<<setw(2)<<h<<":"<<setw(2)
		<<m<<":"<<setw(2)<<s<<flush<<"\r";//setw(2),��˼��������λ������������flush��ˢ�»������� ""\r" ������
	}
	//����,ÿ��1��,��ʾһ��
	void run(){
		while(1){//��ʾ��ͣ���ߣ���ѭ��
			show();
			dida();
			time_t cur = time(0);//time(0)��ʾ��ǰʱ��
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

