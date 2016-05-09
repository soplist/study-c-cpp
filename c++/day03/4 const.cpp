#include <iostream>
using namespace std;
class Sample{
	const int ci;
	int& ri;//引用
public:
	//对于const,引用成员,只能用初始化列表完成初始化，因为初始化列表是在分配内存空间的同时初始化的
	Sample(const int c, int& r)
		:ci(c),ri(r){ }	
	void show(){
		cout << ci << ',' << ri << endl;
	}
};
int main()
{
	int x = 200;
	Sample s(100, x);
        s.show();
}


