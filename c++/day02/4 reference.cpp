#include <iostream>
using namespace std;

int main()
{
	int x = 10;
	//�������ñ���r,���õ�����x,�൱�ڸ�����x���˸�����:r
	int& r = x;
	r = 20;
	cout << "x=" << x << endl;
	//���ñ��������ʼ��,���ñ����ڴ���ʱ�������õ�ĳһ�������ϡ�
	//int& r2;
	//ֻ��const���òſ������õ�������
	//int& r3 = 30;
	const int& r4 = 40;
	//�ٸ�����x�����
	int& r5 = x;
	r5 = 50;
	cout << "r=" << r << endl;
	cout << "x=" << x << endl;
	cout << "&r=" << &r << endl;
	cout << "&r5=" << &r5 << endl;
	cout << "&x=" << &x << endl;
	int y = 200;
	//�����ı���һ������,�Ͳ��ɸı�	
	r = y;//x = y;

	int& r6 = r;//int& r6 = x;
}
/*
�������õı����Ǹ����������.
�������õķ�ʽ: ����& = ������;

*/
