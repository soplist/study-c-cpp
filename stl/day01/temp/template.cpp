#include <iostream>
#include "buffer.h"
using namespace std;
int main()
{
	Buffer<int> buf;//生成新类
	buf.push(1);buf.push(2);
	cout << buf.get() << endl;
	cout << buf.get() << endl;
	Buffer<string> buf2;//生成新类
	buf2.push("abc");	
	Buffer<double> buf3;//生成新类
	Buffer<int> buf4;//不生成类
	cout << typeid(buf).name() << endl;
	cout << typeid(buf2).name() << endl;
	cout << typeid(buf4).name() << endl;
}

