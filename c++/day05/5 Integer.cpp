#include <iostream>
using namespace std;
//整数类
class Integer{
	int x;
public: 
	Integer(int x=0):x(x){}//构造函数
	friend ostream& operator<<(
		ostream&o,const Integer&i){
		return o<<i.x;
	}
	friend istream& operator>>(//把声明和定义都写在类的里面，但是这个函数还是全局
		istream&is, Integer&i){
			return is>>i.x;
	}
	friend const Integer operator+//Integer是类型
	(const Integer&i1, const Integer&i2){
		return Integer(i1.x + i2.x);
	}
/*
	const Integer operator+
		(const Integer&i)const{
		return Integer(x+i.x);
	}
*/
};
int main()
{
	Integer i(100);//构造对象
	Integer i1 = 100;//相当于Integer i1(100);
	cout << i1 << endl;
	Integer i2 = i1 + 200;	
	cout << i2 << endl;	
	i2 = 200 + i1;
	cout << i2 << endl;	
}

