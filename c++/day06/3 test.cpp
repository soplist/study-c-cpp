#include <iostream>
using namespace std;
/*�����������͵��������������
int operator+(int a, int b){
	return a - b;
}
*/
class Integer{
	int x;
public:
	Integer(int x=0):x(x){}
	//���ܴ��������
	//int operator#(){ return x;}
	//���������������򲻿ɸı�,���粻�ܽ�˫Ŀ��������سɵ�Ŀ�����,����������ȼ�Ҳ���ܱ��ı�
	/*
	friend Integer operator%
		(const Integer&i1){
		return Integer(x%10);
	}	
	*/
};
int main()
{
	int x = 10;
	int y = 20;
	int z = x + y;
}

