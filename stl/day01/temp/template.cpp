#include <iostream>
#include "buffer.h"
using namespace std;
int main()
{
	Buffer<int> buf;//��������
	buf.push(1);buf.push(2);
	cout << buf.get() << endl;
	cout << buf.get() << endl;
	Buffer<string> buf2;//��������
	buf2.push("abc");	
	Buffer<double> buf3;//��������
	Buffer<int> buf4;//��������
	cout << typeid(buf).name() << endl;
	cout << typeid(buf2).name() << endl;
	cout << typeid(buf4).name() << endl;
}

