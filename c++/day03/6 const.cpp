#include <iostream>
using namespace std;

class Sample{
	int x;
	mutable int y;
public:
	Sample(int x=0):x(x){}
	void setX(int x){this->x = x;}//�޸�x��
	//ֻ������
	int getX()const{return x;}	//��ȡx
	void show()const{cout<<"x="<<x<<endl;}//��const��Ϊ�˸��߱�������������������޸ĳ�Ա�������������������������
	void show(){cout<<"##x="<<x<<endl;}
	//ֻ�����������޸�mutable�ĳ�Ա����
	void setY(int y)const{ this->y=y; }
};

int main()
{
	Sample s;
	s.show();
	//s.setX(100);
	s.show();
	cout << s.getX() << endl;
}

/*4.ֻ������const
	4.1 ��ֻ������ֻ�ܵ���ֻ������,���ܵ��÷�ֻ������.���ڷ�ֻ������,�����Ե��÷�ֻ������,Ҳ���Ե���ֻ������.
	4.2 ���һ����ĳ�Ա���������޸ĳ�Ա������ֵ,��ô,�Ͱ���(��Ա����)������ֻ������.
	4.3 ֻ���ͷ�ֻ�����������γ����ع�ϵ.��ʱ,����ֻ������,ֻ�ܵ���ֻ������,����ֻ�����������ѡ���ֻ������.
	4.4 �������:
		ֻ�����������޸�����Ϊmutable�ĳ�Ա����.*/
