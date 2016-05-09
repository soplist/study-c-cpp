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
	f(c);//类型的自动转换，传参相当于赋值,d = c;
	f(s); f(i); f(fl); f(d);//重载，自动找到想对应的函数调用
}
//c++中比Int小的类型自动提升为int,如果没有Int,那么就看哪个合适，如果多个都合适，就会报错，c语言中会逐级向上找，只找一个，即使有多个合适也找最近的那个
