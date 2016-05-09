#include <iostream>
using namespace std;

int main()
{
	//缓冲区的内容输出到显示器的5种情况：1.有输入,2.手动刷新,3.程序运行结束,4.输出换行,5.缓冲区满 会清空缓冲区（就是把缓冲区里面的数据送到显示器上）
	//标准输出带缓冲区,可以重定向
	cout << "Hello";//标准输出，有缓冲区
	//cout << flush;
	//日志输出同cerr
	clog << "LOGGER";//标准日志输出，没有缓冲区
	//错误输出不带缓冲区,不能重定向
	cerr << "ERROR";//标准错误输出
	int x;
	cin >> x; 
}

//a.out 1>a.txt重定向， 1标准输出重定向，2标准错误输出重定向
