#include <iostream>
using namespace std;
void f(char c){
	cout << "f(char)" << endl;
}

void f(short s){
	cout << "f(short)" << endl;
}
void f(int i){
	cout << "f(int)" << endl;
}
void f(long l){
	cout << "f(long)" << endl;
}
void f(float f){
	cout << "f(float)" << endl;
}
void f(double d)
	{cout << "f(double)" << endl;}

int main()
{
	char c = 'A';//
	short s = 10;
	int i = 20;
	long l = 30;
	float fl = 3.14F;
	double d = 3.14;
	f(c);//���͵��Զ�ת���������൱�ڸ�ֵ,d = c;
	f(s); f(i); f(fl); f(d);//���أ��Զ��ҵ����Ӧ�ĺ�������
}
//c++�б�IntС�������Զ�����Ϊint,���û��Int,��ô�Ϳ��ĸ����ʣ������������ʣ��ͻᱨ��c�����л��������ң�ֻ��һ������ʹ�ж������Ҳ��������Ǹ�
