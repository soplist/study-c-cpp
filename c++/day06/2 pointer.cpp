#include <iostream>
using namespace std;
class IntPtr{
	int* ptr;
public:
	IntPtr(int* ptr=NULL):ptr(ptr){}	
	int& operator*(){ return *ptr; }//���ص��ǣ�ptrָ����Ǹ�����Ҳ���Ƿ��ض���������Ҫ������	
};
int main()
{
	int x = 100;
	IntPtr ptr = &x;	
	*ptr = 200;//ptr.operator*() = 200;
	cout << x << endl;	
}

