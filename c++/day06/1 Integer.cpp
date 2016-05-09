#include <iostream>
using namespace std;
class Integer{
	int x;
public:
	Integer(int x=0):x(x){}
	friend ostream& operator<<
		(ostream&o,const Integer&i){
		return o<<i.x;
	}
	//成员
	const Integer operator~()const{/*对当前对象进行按位取反，所以括号里面没有参
    数，第一个const是为了防止临时变量作为左值出现，第二个const表示当前的函数没有
    修改成员变量的值*/

		return Integer(~x);//返回的是个临时值
	}	
	//前加加
	Integer& operator++(){
		x++;
		return *this; //结果返回的是当前对象本身*this，函数的返回类型是当前对象的引用
	}
	//后加加
	const Integer operator++(int){//参数是哑元，只有类型，无用，用来区分前加加和后加加
		Integer old = *this;//把当前对象保存在一个临时值里面
		x++;//当前对象+1
		return old;//结果返回原来的对象，的是个临时值，这个值用来参与运算
	}
	operator*(){

	}	

	//友元
/*
	friend const Integer 
		operator~(const Integer&i){
		return Integer(~i.x);
	}	
*/
};
int main()
{
	Integer i1 = 100;
	cout << (~i1) << endl;		
	int x = 10;
	++x = 100;
	cout << "x=" << x << endl;
	++i1;
	cout << "i1=" << i1 << endl;
	++i1 = 200;//i1.operator++() = 200;
	cout << "i1=" << i1 << endl;	
	i1 = 100;
	cout << (i1++) << endl;
	//i1.operator++(int) + 200	
	cout << "i1=" << i1 << endl;
}

