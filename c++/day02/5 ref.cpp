#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void swap2(int& a, int& b){
//a����x, b����y
	int t = a;//int t = x;
	a = b;//x = y;
	b = t;//y = t;
}

int main()
{
	int x = 10;
	int y = 20;
	swap(&x, &y);//��ַ����
	cout<<"x="<<x<<",y="<<y<<endl;	
	swap2(x, y);//���ô���
	cout<<"x="<<x<<",y="<<y<<endl;	
	int i1 = 11;
	int i2 = 22;
	swap2(i1, i2);
	cout<<i1<<","<<i2<<endl;
	void print(const int&);
	print(i1);
	cout << i1 << endl;
	print(12345);
}
void print(const int& x)
	{ cout << x << endl;}
int& fa(){
	int x = 1234;
	return x;//���ܷ��ؾֲ�����������
}
/*
�������βο�������������
ͨ�����ô��ݲ�������֮Ϊ���ô���
��const���������ò����Ĵ���
����ʹ�����ô��ݲ���
����ʹ�����ô���ָ��
��Զ��Ҫ���ضԾֲ����������ã����Ǿֲ������Ǿ�̬�Ļ����ڶ�̬�ڴ��з����


const ���ò���:
		����������Ҫ�������ò�����ֵʱ,�����������ò���ǰ��const. �ô�:
		1)��ֹ��С���޸ı�����ֵ��
		2)����ʱ���Խ��ܳ�������
*/





