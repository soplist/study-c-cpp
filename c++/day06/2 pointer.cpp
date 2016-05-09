#include <iostream>
using namespace std;
class IntPtr{
	int* ptr;
public:
	IntPtr(int* ptr=NULL):ptr(ptr){}	
	int& operator*(){ return *ptr; }//返回的是＊ptr指向的那个对象，也就是返回对象本身，所以要用引用	
};
int main()
{
	int x = 100;
	IntPtr ptr = &x;	
	*ptr = 200;//ptr.operator*() = 200;
	cout << x << endl;	
}

