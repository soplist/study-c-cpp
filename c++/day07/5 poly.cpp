#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//交通工具
class V{
public:
	virtual void run(){}
	virtual void stop(){}	
};
class Car : public V{
public:
	virtual void run(){
		cout << "小汽车过马路" << endl;
	}	
	virtual void stop(){
		cout << "小汽车等红灯" << endl;
	}
};
class Bus : public V{
public:
	virtual void run(){
		cout << "公共汽车过马路" << endl;
	}	
	virtual void stop(){
		cout << "公共汽车等红灯" << endl;
	}
};
class NO11 : public V{
public:
	virtual void run(){
		cout << "行人过马路" << endl;
	}	
	virtual void stop(){
		cout << "行人等红灯" << endl;
	}
};

void run(V* v){
	v->run();//通过父类型的指针调用具体的函数
}
void stop(V& v){
	v.stop();
}

int main()
{
	V* vs[5] = {//这是一个数组，这个数组里面每一个元素都是指针，这个指针的类型是父类型的，五个父类型的指针可以指向五个不同的对象，唯一的要求是这个对象只能是这个类型的对象或者是他子类的对象
		new Bus(), new NO11(), new Car(), new Bus(), new Car()
	};
	vs[0]->run();//vs[0]是数组的第一个元素，也就是一个指针，他指向Bus()里面的对象，在程序运行期间调用Bus里面的函数
      //父类型的指针可以指向子类型的对象
	run(new Car());
	run(new Bus());
	run(new NO11());
   //父类型的引用可以引用到子类型的对象
	Car c;
	Bus b;
	stop(c);
	stop(b);
}

