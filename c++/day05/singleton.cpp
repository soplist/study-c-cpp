#include <iostream>
using namespace std;
//Example���ǵ�����,ֻ�ܴ���һ���������
class Example{
	int x;
	Example(){}//���캯��˽�У������Ͳ��ܹ�������ˣ�
	static Example e;//ֱ�ӹ����һ��������
	Example(const Example&){}//�ѿ�������Ҳ˽��
public:
	static Example& getInstance(){
		return e;	//ÿ�ζ�����ͬһ������
	}		
};
Example Example::e;//����ռ�  ǰһ��Example ����������һ��Example ������
int main()
{
	Example& e1 = Example::getInstance();//ͨ������::����   Example::getInstance()������e ��e1���õ�e��

	Example& e2 = Example::getInstance();
	cout << &e1 << "," << &e2 << endl;
}
