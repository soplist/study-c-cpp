#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void swap2(int& a, int& b){
//a就是x, b就是y
	int t = a;//int t = x;
	a = b;//x = y;
	b = t;//y = t;
}

int main()
{
	int x = 10;
	int y = 20;
	swap(&x, &y);//地址传递
	cout<<"x="<<x<<",y="<<y<<endl;	
	swap2(x, y);//引用传递
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
	return x;//不能返回局部变量的引用
}
/*
函数的形参可以是引用类型
通过引用传递参数，称之为引用传递
用const来保护引用参数的传递
尽量使用引用传递参数
尽量使用引用代替指针
永远不要返回对局部变量的引用，除非局部变量是静态的或是在动态内存中分配的


const 引用参数:
		当函数不需要引发引用参数的值时,尽量将此引用参数前加const. 好处:
		1)防止不小心修改变量的值。
		2)调用时可以接受常量参数
*/





