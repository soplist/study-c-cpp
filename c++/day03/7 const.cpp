#include <iostream>
using namespace std;

class Sample{
	int x;
	mutable int y;
public:
	Sample(int x=0):x(x){}
	void setX(int x){this->x = x;}
	int getX()const{return x;}	
	void show()const{cout<<"x="<<x<<endl;}
	void show(){cout<<"##x="<<x<<endl;}
	void setY(int y)const{ this->y=y; }
};

void fa(Sample s){ s.show(); }
void fb(Sample& s){ s.setX(200); }
void fc(const Sample& s){
	//s.setX(300);//���ܵ��÷�ֻ������
	s.show();
}
//ʵ�ʿ�����,���ټ����²���
void fd(const Sample s){ }
int main()
{
	Sample s(100);
	fa(s);//ֵ����
	fb(s);
	s.show();	
	fc(s);//��ֻ�����󴫸�ֻ������
	const Sample s2;//s2�Ǹ�ֻ���Ķ���
	fc(s2);
//	fb(s2);//���ܽ�ֻ�����󴫸���ֻ������
}

