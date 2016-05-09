#include <iostream>
using namespace std;
//������
class F{
	int n;//����
	int d;//��ĸ
public:
	F(int n=0, int d=1):n(n),d(d){}
	//������Ԫ
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
const F operator+ //FΪ f1+f2�Ľ���Ǹ���ʱֵ���Ǹ��µĶ���Fǰ��const�ĺô��ǰѷ���ֵ����һ����������
	(const F& f1, const F& f2){//�����ã���ֹ����������һ�㶼��const
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
	//(f1 + f2) = f3;f1+f2�Ľ���Ǹ���ʱֵ��������Ϊ��ֵ����
	f3 = f1 - f2;
	cout << "f3=" << f3 << endl;
	f3 = f1 * f2;
	cout << "f3=" << f3 << endl;
	f3 = f1 / f2;
	cout << "f3=" << f3 << endl;
	cout << (f1 < f2) << endl;	
}




