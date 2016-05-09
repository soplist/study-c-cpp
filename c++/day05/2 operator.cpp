#include <iostream>
using namespace std;
//分数类
class F{
	int n;//分子
	int d;//分母
public:
	F(int n=0, int d=1):n(n),d(d){}
	//声明友元  可以访问私有成员
	friend ostream& 
		operator<<(ostream&,const F&);//,const F& 当我需要打印某一个分数对象的时候不需要拷贝一份过来，打印拷贝的那份，
                                                                                           //  前面加const说名，既可以传只读的 对象也可以传非只读的打印
	friend istream&
		operator>>(istream&,F&);//如果F不是引用 f就是个复制出来的临时对象，不是对象本身，输入的值就给这个临时对象的，，输入完成后就释放了
};
ostream&operator<<(ostream&o,const F&f){//o的类型是ostream&  ostream的拷贝构造是私有的，所以要用引用
	o<<f.n<<'/'<<f.d;//cout 就是o
	return o;//返回本身，这样就可以连续的打印
}
istream&operator>>(istream&i,F&f){
	char c;
	i>>f.n>>c>>f.d;//cin 就是
	return i;
}

int main()
{
	int x = 100;
	cout << x << endl;//cout是类，cout是ostream类型，operator是函数，打印x实际上是调用cout这个类里面operator函数及cout.operator(),把x作为参数传过去
	cout.operator<<(x).operator<<(endl);//operator<< 返回的就是当前对象cout,当他打印完x之后返回cout,然后用cout继续打印endl;
	cout << endl;//
	F f(1,2);
	cout << f << endl;//f的类型是F，在cout.operator()的所有重载函数里面没有这个类型，所以不能打印f
     //cout.operator<<x   /cout是ostream类的对象，要想让cout能打印f就要先修改ostream这个类，但是ostream是不能修改的
    //   operator<<(cout,f)
	operator<<(cout,f).operator<<(endl);//cout就是ostream& o的引用，所以o就是cout，cout就是o
	F f2(3,4);
	cout << "f2=" << f2 << endl;
	F f3(3,5);
	cout << "f3=" << f3 << endl;
	cout << "----------------" << endl;
	cout << "请输入一个整数:";
	cin >> x;//cin ==> istream
	cout << "请输入一个分数:";
	cin >> f;//operator>>(cin,f);
	cout << "f=" << f << endl;
}

/*
在c++里面任何一个运算符都是函数，打印一个数据实际上就是调用这个函数
*/


