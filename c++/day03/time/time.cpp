//��Ķ��� Ҳ����ʵ��
#include <iostream>
#include <ctime>
#include <iomanip>
#include "time.h"
using namespace std;
Time::Time(int h, int m, int s)
	:h(h),m(m),s(s) { }	
void Time::dida(){
	s++;
	if(s==60){ s=0; m++; }	
	if(m==60){ m=0; h++; }
	if(h==24){ h=0;}
}
void Time::show(){
	cout<<setfill('0');
	cout<<setw(2)<<h<<":"<<setw(2)
	<<m<<":"<<setw(2)<<s<<flush<<"\r";
}
void Time::run(){
	while(1){
		show();
		dida();
		time_t cur = time(0);
		while(time(0)==cur);		
	}
}
//��סҪ�ں�����ǰ��� ����::   ,�����ڷ���ֵǰ��
// g++ -c ���� ����  .o�ļ�
//g++ .c �ļ�  ��������
//  g++ .o  .o �����ļ����γ�һ������ִ�еĳ���