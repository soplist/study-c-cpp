#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Time{
	int h;
	int m;
	int s;
public:
/*   ����ͨ������ʼ����Ա����
	void set(int a, int b, int c){
		h = a; m = b; s = c;
	}
*/
	//���캯�� ��ʼ����Ա�����������б����û��
	Time(int a, int b, int c){
		cout<<"Time(int,int,int)"<<endl;
		h = a; m = b; s = c;
	}	
	//�ղι���
	Time(){
		cout << "Time()" << endl;
		h = m = s = 0;
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
	Time t(0, 0, 0);//����һ�����������൱�ڹ���һ�����󣬴�����������Ϊ�˵����Լ�д�Ĺ��캯��
//      Time t;  ����Ĭ�ϵĿղι��캯��
	//t.h=0; t.m=0; t.s=0;
	//t.run();
	Time t2(23,59,55);
//	t2.run();
	Time t3; 
	t3.run();//���ÿղι��캯��
}

//��Ա����ͨ����˽�еģ���Ա����һ���ǹ����ģ������������ǹ����ģ�������ʵ�������صģ�
//һ������������ж�����캯�������캯��Ҳ�Ǻ��������к������������������أ����ھ�������ĸ��Ϳ��㴫����������
