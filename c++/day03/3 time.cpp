#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Time{
	int h;
	int m;
	int s;
public:
	//�ó�ʼ���б�򻯹��캯����ʵ��
	Time(int h=0, int m=0, int s=0)
		:h(h),m(m),s(s) { }	//h(h) ���������h�ǳ�Ա�����������h�ǲ�������˼���ò���h��ʼ����Ա����,�����ʼ�����������ڴ�ռ�ʱ��ʼ����
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
/*��ʼ���б���Լ򻯹��캯����ʵ��.
		��ʼ���б�ĳ�ʼ��Ϊ�����ڶ�������ڴ��ڼ�,�Գ�Ա�����ĳ�ʼ��ʱ��ȹ��캯������. �ô�:
		1)Ч�ʻ��һ���
		2)�Գ�const��Ա,���ó�ԱҲͬ����Ч.*/
