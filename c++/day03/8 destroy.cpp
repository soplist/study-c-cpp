#include <iostream>
#include <string>
using namespace std;
class Person{
	string name;
	int age;
	bool gender;
public:
	Person(string name="",int age=0,
		bool gender=true){
		this->name = name;
		this->age = age;
		this->gender = gender;
		cout << "Person(s,i,b)" << endl;
	}
	void show(){
		cout << name<< ',' << age << ',' <<
			(gender?"男":"女") << endl;
	}	
	//析构函数
	~Person(){
		cout << "~Person()" << endl;
	}
};
int main()
{
	cout << "-------------------\n";
	if(1){//逻辑真
		Person p("Daniel", 30, true);//调用构造函数构造对象
		p.show();
	}//p 出if语句前面调用析构函数
	cout << "-------------------\n";
	Person* pi = 
		new Person("Guodh",31,true);//在堆里面构造对象	
	delete pi;//之后调用析构函数
}
//析构函数没有参数，所以就没有重载，一个类里析构函数有且只有一个析构函数，在对象销毁前自动调用
