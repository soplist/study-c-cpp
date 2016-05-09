#include <iostream>
using namespace std;
class F{
	int n;
	int d;
public:
	F(int n=0, int d=1):n(n),d(d){}
	const F operator+(const F& f)const{
		return F(n*f.d+d*f.n,d*f.d);
	}
/*
	friend const F 
		operator+(const F&f1,const F&f2){
	}
*/
	const F operator-(const F& f)const{
		return F(n*f.d-d*f.n,d*f.d);
	}
	friend ostream& 
		operator<<(ostream&,const F&);
};
ostream&operator<<(ostream&o,const F&f){
	o<<f.n<<'/'<<f.d;
	return o;
}

int main()
{
	F f1(1,2);
	F f2(2,3);
	F f3 = f1 + f2;
//	F f3 = operator+(f1, f2);	
//	F f3 = f1.operator+(f2);
	cout << "f3=" << f3 << endl;
	const F f4(3,4);
	const F f5(2,5);
	F f6 = f4 + f5;
	f4.operator+(f5);
	cout << "f6=" << f6 << endl; 

}




