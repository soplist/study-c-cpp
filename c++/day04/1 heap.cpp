#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class Date{
public:
	int y,m,d;
	Date(int y=0, int m=0, int d=0)
		:y(y),m(m),d(d){
		cout << "Date(i,i,i)" << endl;
	}
	~Date(){cout<<"~Date()"<<endl;}
	string toString(){//toString函数，返回年月日的字符串
		char buf[20] = {};
		sprintf(buf,
			"%04d-%02d-%02d",y,m,d);
		return buf;
	}
};

class Emp{
	string name;
	Date birth;
public:
	Emp(string n=""):name(n){
		cout << "Emp(string)" << endl;
	}	
	~Emp(){cout << "~Emp()" << endl;}
	void show(){
		cout << name << "," 
			<< birth.toString() << endl;
	}
};

int main()
{
	//在栈中构造对象
	Date d;
	Date d2(2012,9,23);//没有参数就不要写括号，有参数才可以些括号
	Date* pd;
	Date& rd = d;//不会构造对象
	pd = new Date();//在堆中构造对象	
	cout << pd->toString() << endl;//pd->toString等价于(*pd).toString()
	delete pd;
	pd = NULL;//把指向这个对象的指针赋值为NULL,不然这个指针就是悬空指针	
	pd = new Date(2012,12,21);
	cout << pd->toString() << endl;
	delete pd;
	cout << "------------------" << endl;
	Date* pd2=(Date*)malloc(sizeof(Date));
	pd2->y = 2013;
	pd2->m = 1;
	pd2->d = 1;
	cout << pd2->toString() << endl;
	free(pd2);
	cout << "------------------" << endl;
	Emp* pe = new Emp("Daniel");//如果成员变量是对象，先构造对象，然后调用构造函数
	pe->show();
	delete pe;
	cout << "------------------" << endl;
	Emp* pe2 = (Emp*)malloc(sizeof(Emp));//malloc 只能分配内存空间，其他俩步都没做
	pe2->show();
	free(pe2);
	cout << "------------------" << endl;
}
/*1.1 new 和 malloc的区别
		1)malloc只负责分配内存空间,并不会调用对象的构造函数,对象销毁时,也不会调用析构函数。
		2)malloc需要进行类型转换,而new已经把类型转换好了。*/
