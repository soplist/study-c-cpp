#include <iostream>
using namespace std;
struct Dog{
	//成员变量
	string name;
	string bread;
	int age;
	//成员函数
	void eat(){
		cout << "狗吃" << endl;
	}
	void sleep(){
		cout << "狗睡" << endl;
	}
	void grow(){ age++; }
	void show(){
		cout << "我叫" << name << ",是"
			<< bread << "品种" << ",今年"
			<< age << "岁了" << endl;
	}
};
int main()
{
	//用类声明一个变量,相当于构造一个对象
	Dog d;//在栈中构造
	d.name = "旺财";
	d.bread = "泰迪";
	d.age = 2;
	d.eat();
	d.sleep();
	d.grow();
	d.show();	
	Dog* pd = new Dog;//在堆中构造
	pd->name = "Mu";
	pd->bread = "金毛";
	pd->age = 1;
	pd->eat();
	pd->sleep();
	pd->grow();
	pd->show();	
	delete pd;//记得要释放
	pd = NULL;

	//必须通过对象调用成员函数,没有对象无法调用成员函数
	//Dog::eat();




}
//对象就是一个变量

