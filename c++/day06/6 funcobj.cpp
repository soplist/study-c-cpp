#include <iostream>
using namespace std;
//加法器
class Add{
	int x;
public:
	Add(int x=0):x(x){}
	void operator()(int& r){
		r += x;
	}	
	void operator()(){
		cout<<"哈哈,我是括号运算符"<<endl;
	}
};
int main()
{
	Add a = 5;
	int i = 100;
	//a是对象,但可以像函数一样调用,故称函数对象
	a(i);//像调用函数a,传参数i
	cout << i << endl;
	a();
}

