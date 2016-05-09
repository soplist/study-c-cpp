#include <iostream>
using namespace std;

int main()
{
	int x = 10;
	//定义引用变量r,引用到变量x,相当于给变量x起了个别名:r
	int& r = x;
	r = 20;
	cout << "x=" << x << endl;
	//引用变量必须初始化,引用变量在创建时必须引用到某一个变量上。
	//int& r2;
	//只有const引用才可以引用到常量上
	//int& r3 = 30;
	const int& r4 = 40;
	//再给变量x起别名
	int& r5 = x;
	r5 = 50;
	cout << "r=" << r << endl;
	cout << "x=" << x << endl;
	cout << "&r=" << &r << endl;
	cout << "&r5=" << &r5 << endl;
	cout << "&x=" << &x << endl;
	int y = 200;
	//变量的别名一旦定义,就不可改变	
	r = y;//x = y;

	int& r6 = r;//int& r6 = x;
}
/*
定义引用的本质是给变量起别名.
定义引用的方式: 类型& = 变量名;

*/
