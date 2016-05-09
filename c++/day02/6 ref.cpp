#include <iostream>
using namespace std;
//返回引用相当于返回变量(x)本身
int& fa(){
	static int x = 10;
	return x;
}

int main()
{
	cout << fa() << endl;
	int& r = fa();//int& r = x;调用fa()返回的是x的引用，定义一个int型的引用来接收x的引用，相当于在给x起个别名r
	r++;//x++;
	cout << fa() << endl;//cout<<x<<endl;
	int r2 = fa();//int r2 = x;赋值，对r2进行运算，不会影响x
	r2++;
	cout << fa() << endl;
	fa() = 100;//x=100;
	cout << fa() << endl;



}

