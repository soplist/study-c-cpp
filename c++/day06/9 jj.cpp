#include <iostream>
using namespace std;
struct Date{
	int y;
	int m;
	int d;
};

class DatePtr{
	Date* ptr;
public:
	DatePtr(Date* ptr=NULL):ptr(ptr){}//构造函数
	Date& operator*(){ return *ptr; }	//重载*号运算符，返回的是值本身
	Date* operator->(){ return ptr; }//重载->运算符，返回的是指针（地址）；
	DatePtr& operator++(){
		ptr++;
		return *this;
	}	
	Date& operator[](int index){
		return *(ptr+index);
	}	
};
int main()
{
	Date d = {2012, 9, 27};
	DatePtr p = &d;
	(*p).y = 2013;//p.operator*().y=2013
	p->m = 10;//p.operator->()->m = 10;
	cout << d.y << '-' << d.m 
		<< '-' << d.d << endl;
	Date ds[3] = {
		{2012,9,27},{2012,9,30},{2012,12,21
	}};	
	DatePtr p2 = ds;
	for(int i=0; i<3; i++){
		cout << p2->y << '-' << p2->m
			<< '-' << p2->d << endl;
		++p2;
/*
		cout << p2[i].y << '-' << p2[i].m
			<< '-' << p2[i].d << endl;
*/
	}	
}

