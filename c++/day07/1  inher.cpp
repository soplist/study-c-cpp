#include <iostream>
using namespace std;
//����,����
class Parent{
	private: int i1;//��Ա����Ҳ�����ǹ�����������˽�е�
	protected: int i2;
	public: int i3;
};
//����,������
class Child1 : public Parent{//�����ļ̳�
public:
	void show(){
		//i1++;//��������˽�е��������ﲻ�ܷ���
		i2++;//ֻ��������ڲ���������ڲ�����
		i3++;
	}
};

class Child2 : private Parent{//˽�еļ̳У������ĵļ̳У�������ⲿ��ȫ���ܷ���
public:
	void show(){
		//i1++;
		i2++;
		i3++;
	}	
};

class Child3 : protected Parent{//�����ļ̳�
public:
	void show(){
		//i1++;
		i2++;
		i3++;
	}
};

int main()
{
	Parent p;
	//p.i1 = 10;//˽�еģ�ֻ��������ڲ�����
	//p.i2 = 20;//�����ģ�ֻ��������ڲ���������ڲ�����
	p.i3 = 30;		
	Child1 c1;
	//c1.i1 = 10;
	//c1.i2 = 20;
	c1.i3 = 30;	
	Child2 c2;
	//c2.i1 = 10;
	//c2.i2 = 20;
	//c2.i3 = 30;//˽�еļ̳У�������ⲿ���ܷ���
	Child3 c3;
	//c3.i1 = 10;
	//c3.i2 = 20;
	//c3.i3 = 30;�����ĳ�Ա��������ⲿ��˵��˽�е�.
}

