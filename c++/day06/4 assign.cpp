#include <iostream>
using namespace std;

class F{
	int n;
	int d;
public:
	F(int n=0, int d=1):n(n),d(d){}
	friend ostream& 
		operator<<(ostream&o, const F& f){
		return o<<f.n<<'/'<<f.d;
	}	
	F& operator=(const F& f){//赋值是相同类型的才能赋值
		n = f.n;
		d = f.d;			
		return *this;
	}
	F& operator+=(const F& f){
		n = n*f.d + d*f.n;
		d = d*f.d;
		return *this;
	}
	friend const F operator+
		(const F&f1, const F&f2){
		return F(f1.n*f2.d+f1.d*f2.n,
			f1.d*f2.d);//返回的是临时值
	}
};

int main()
{
	F f1(1, 2);//构造函数
	F f2 = f1;//拷贝构造
	F f3;//空参构造
	f3 = f1;//赋值
	f3.operator=(f1);	
	cout << "f3=" << f3 << endl;
	int a, b, c, d;
	cout << &(a = b = c = d = 0) <<endl;
	cout << &a << endl;
	f1 += f2;
	cout << "f1=" << f1 << endl;	

}

