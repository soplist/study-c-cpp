#include <iostream>
using namespace std;
class Date{
	int y,m,d;
public:
	Date(int y=0, int m=0, int d=0)
		:y(y),m(m),d(d){
		cout<<"Date(i,i,i), "<<this<<endl;
	}
	~Date()
		{cout<<"~Date(), "<<this<<endl;}
};
class Emp{
	string name;//name是个对象，要构造对象
	Date* birth;
	double salary;
public:
	Emp(string n, int y, int m, int d, 
		double s):name(n),salary(s){
		birth = new Date(y,m,d);		
		cout << "Emp(s,i,i,i,d), " 
			<< this << endl;
	}
	~Emp(){
		delete birth;//防止内存泄露
		birth = NULL;
		cout <<"~Emp(), "<<this<<endl;
	}
	//提供拷贝构造函数,完成对象的深拷贝
	Emp(const Emp& e){
		cout<<"Emp(const Emp&)"<<endl;
		name = e.name;
		birth = new Date(*e.birth); //e.birth是一个指针，对它进行＊号运算就是对象本身
		salary = e.salary;
	}		
};

int main()
{
	Emp e("Daniel",1980,2,25,160000);
	Emp e2 = e;	
}
//当类需要实现深拷贝时,一般是类中的成员变量是指针, 并指向了堆中的内存,就得提供自定义的深拷贝构造函数,编译器默认的拷贝构造函数已经不能满足要求。
