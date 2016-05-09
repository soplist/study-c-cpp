#include <iostream>
using namespace std;

int main()
{
	double d = 3.14159;
	int i = (int)d;//在c语言中可以，在c++中会有警告，一般情况下是错无的，只有double转成int警告，为了兼容c
	cout << i << endl;	
	i = int(d);
	cout << i << endl;	
	i = static_cast<int>(d);
	cout << i << endl;	
	void* p = malloc(40);
	int* pi = static_cast<int*>(p);
	//做一定的静态类型检查
	//double* pd = static_cast<double*>(pi);int*不能转换成double*
	//不同类型的指针之间使用的转换方式
	double* pd = reinterpret_cast<double*>(pi);
	//取消cv限制 
	const volatile int ci = 100;
	//const int* pci = &ci;
	int* pci = const_cast<int*>(&ci);
	*pci = 200;
	cout << ci << endl;//编译器认为ci是常量，打印ci就是打印100，加一个volatile ，意思是这个变量是一个随时可以改变的值	，这个时候就会打印200
       cout<<*pci<<endl;	
}

/*
static_cast<类型>()
转换时做静态检查，即在编译时进行
void*到其他指针的转换
reinterprect_cast<类型>()
允许强转任何类型的指针
把整数强转成指针，指针强转成整数
const_cast<类型>()
去掉cv限制 const volatile
dynamic_case<类型>()
动态转换
*/
