#include <iostream>
using namespace std;
//ÀàÄ£°å
template <typename T> class Buffer{
	T buf[100];
	int sz;
public:
	Buffer():sz(){}
	void push(T x){ buf[sz++] = x;}	
	T get(){ sz--; return buf[sz]; }	
};
Buffer<string> fa(Buffer<string> buf){
	return buf;
}
int main()
{
	Buffer<int> buf;
	Buffer<int>* pb;
	Buffer<int>& rb = buf;
}


