#include <iostream>
using namespace std;
class Parent{
public:
	Parent(){cout << "Parent()" << endl;}
	virtual ~Parent(){cout<<"~Parent()"<<endl;}//�������������ڰ󶨣��������ھ��������ĸ�����,�麯���ĵ���ȡ�����麯���б���ȡ���ڱ�����
	virtual void show(){}
};
class Child : public Parent{
public:
	Child(){cout << "Child()" << endl;}
	virtual ~Child(){cout << "~Child()" << endl;}
};
int main()
{
	Parent* p = new Child;
	delete p;
}

/*������
	�������֧�ֶ�̬��,��ô��������Ӧ�����麯��.*/
