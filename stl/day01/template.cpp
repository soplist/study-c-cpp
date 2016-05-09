#include <iostream>
using namespace std;
//类模板
template <typename T> class Buffer{
	T buf[100];//T是泛型类型
	int sz;
public:
	Buffer():sz(){}
	void push(T x){ buf[sz++] = x;}	
	T get(){ sz--; return buf[sz]; }	
};
/*
class Buffer{
	int buf[100];//T是泛型类型
	int sz;
public:
	Buffer():sz(){}
	void push(int x){ buf[sz++] = x;}	
	int get(){ sz--; return buf[sz]; }	
};
class Buffer{
	string buf[100];//T是泛型类型
	int sz;
public:
	Buffer():sz(){}
	void push(string x){ buf[sz++] = x;}
	string get(){sz--;return buf[sz];}	
};
*/
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

