#include <iostream>
#include <cstdio>
using namespace std;
struct Date{
	int year;
	int month;
	int day;
};

int main()
{
	struct Date d = {2012, 12, 21};
	cout << &d.year << endl;	
	cout << &d.month << endl;	
	cout << &d.day << endl;	
	//成员指针,C++中的特殊指针
	//::是域运算符
	int Date::* p1 = &Date::year;//&Date::year;的地址是一个相对地址0，他的类型是是int Date::*类型
	int Date::* p2 = &Date::month;//&Date::month;相对地址为4
	int Date::* p3 = &Date::day;//&Date::day;相对地址为8
	cout << (d.*p1)<<"-"<<(d.*p2)
			<< "-" << (d.*p3) << endl;	
/*
	cout << p1 << endl;//cout 打印出的函数的地址是个true，true就是1
	cout << p2 << endl;
	cout << p3 << endl;
	cout << main << endl;	
	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
*/
	cout << "---------------" << endl;
	Date ds[3] = {
		{2012,12,21},{2010,9,21},{2011,9,3}
	}; 
	void print(Date* ds,int n,int Date::*p);
	print(ds, 3, &Date::day); 
}
void print(Date* ds,int n,int Date::*p){
	for(int i=0; i<n; i++){
		//cout << ds[i].*p << endl;
		cout << (ds+i)->*p << endl;
	}
} 
/*
成员指针是一种相对地址
结构体中的成员(包括变量和函数)的相对地址获取方式
&结构类型名::成员
声明成员指针变量
成员类型 结构类型名::*指针变量名
通过成员指针访问结构成员
结构变量.*指针变量名
结构地址->*指针变量名
*/
