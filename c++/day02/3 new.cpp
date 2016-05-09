#include <iostream>
#include <cstdlib>
using namespace std;
int i = 10;//全局变量
int main()
{
	int x = 10;//在栈中分配
	//=========C风格的分配方式======
	int* p = (int*)malloc(4);//在堆中分配内存空间，malloc返回的是void*类型，c语言的写法int*p=malloc(4)，因为c＋＋类型检查严格所以要强转一下	
	*p = 100;
	free(p);
	p = NULL;
	//=========C++风格==========
	int* p1 = new int;//在堆里面给我分配一个int型的空间
	*p1 = 123;
	cout << *p1 << endl;
	//free(p1);
	delete p1;	
	//分配一个int型空间,初始化为10
	int* p2 = new int(10);
	cout << *p2 << endl;
	delete p2;	
	//分配了10个int型空间
	int* p3 = new int[10];
	for(int i=0; i<10; i++){
		p3[i] = i;
		cout << p3[i] << ' ';
	}
	cout << endl;
	delete[] p3;//注意一定要[]
	//=====定位分配========
	char buf[100] = {};
	int* p4 = new(buf) int;//意思是从buf这个局部变量（栈空间)里分配一个int型内存空间
	*p4 = 0x41424344;
	for(int i=0; i<4; i++){
		cout << buf[i] << ' ';
	}
	cout << endl;
	//delete p4;
}

