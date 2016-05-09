#include <iostream>
using namespace std;
//分数类
class F{
	int n;//分子
	int d;//分母
public:
	F(int n=0, int d=1):n(n),d(d){}
	//声明友元
	friend ostream& 
		operator<<(ostream&,const F&);
	friend const F operator+
		(const F&, const F&);
	friend const F 
		operator-(const F&f1, const F&f2){
		return F(f1.n*f2.d 
			- f1.d*f2.n, f1.d*f2.d);
	}
	friend const F
		operator*(const F&f1, const F&f2){
		return F(f1.n*f2.n, f1.d*f2.d);
	}
	friend const F
		operator/(const F&f1, const F&f2){
		return F(f1.n*f2.d, f1.d*f2.n);
	}
	friend bool 
		operator<(const F&f1, const F&f2){
		return f1.n*f2.d<f1.d*f2.n;
	}
};
ostream&operator<<(ostream&o,const F&f){
	o<<f.n<<'/'<<f.d;
	return o;
}
const F operator+ //F为 f1+f2的结果是个临时值，是个新的对象，F前加const的好处是把返回值当作一个常量来看
	(const F& f1, const F& f2){//传引用，防止拷贝，引用一般都加const
	F f;
	f.n = f1.n*f2.d+f1.d*f2.n;
	f.d = f1.d*f2.d;
	return f;	
}
int main()
{
	F f1(1,2);
	F f2(2,3);
	F f3 = f1 + f2;
	//F f3 = operator+(f1, f2);	
	cout << "f3=" << f3 << endl;
	int x = 10;
	int y = 20;
	//(x + y) = 300;
	//(f1 + f2) = f3;f1+f2的结果是个临时值，不能作为左值出现
	f3 = f1 - f2;
	cout << "f3=" << f3 << endl;
	f3 = f1 * f2;
	cout << "f3=" << f3 << endl;
	f3 = f1 / f2;
	cout << "f3=" << f3 << endl;
	cout << (f1 < f2) << endl;	
}




