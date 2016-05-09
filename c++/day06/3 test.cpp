#include <iostream>
using namespace std;
/*基本数据类型的运算符不能重载
int operator+(int a, int b){
	return a - b;
}
*/
class Integer{
	int x;
public:
	Integer(int x=0):x(x){}
	//不能创建运算符
	//int operator#(){ return x;}
	//运算符的最基本规则不可改变,比如不能将双目运算符重载成单目运算符,运算符的优先级也不能被改变
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

