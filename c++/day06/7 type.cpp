#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class F{
	int n;
	int d;
public:
	F(int n=0, int d=1):n(n), d(d){}
	//类型转换运算符函数
	//将当前对象转成double类型，这个函数不能写返回值
	operator double(){ return n*1.0/d; }
	//将当前对象转成int类型
	operator int()
		{return int(n*1.0/d+0.5);}//四舍五入
	//转成字符串
	operator string(){
		char buf[10] = {};
		sprintf(buf, "%d/%d", n, d);
		return buf;//return string(buf),返回的是string,自动构造一个string类型的临时对象，返回来，自动的把char*类型转换成string 类型
	}
};
void fa(double d){
	cout << "in fa d=" << d << endl;
}
int main()
{
	int x = 3;
	double d;
	d = x;//自动类型转换
	F f1(1,2);
	d = (double)f1;//f1.operator double();
	d = f1;
	fa(f1);	//f1对象可以转换成double类型，因为已经提供了转成double 类型的函数
	int i1 = f1;
	cout << i1 << endl;
	string str = f1;
	cout << str << endl;
}
/*类型转换运算符，没有返回值
   构造函数和析构函数也没有返回值
*/
