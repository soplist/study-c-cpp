#include <iostream>
using namespace std;
class Human{
public:
	Human(){cout<<"Human()"<<endl;}
	void move(){
		cout << "moving moving" << endl;
	}
};
//虚继承
class Peasant : virtual public Human{
public:
	Peasant(){cout<<"Peasant()"<<endl;}//构造函数
	void work(){
		cout << "more work..." << endl;
	}
};
class FootMan : virtual public Human{//构造函数
public:
	FootMan(){cout<<"FootMan()"<<endl;}
	void move(){
		cout << "action" << endl;
	}
	void attack(){
		cout << "atttttacccck.." << endl;
	}
};
class Soldier : 
	public Peasant, public FootMan{//多继承
public:
	Soldier(){cout<<"Soldier"<<endl;}
};


int main()
{
	Soldier s;
	s.work();
	s.attack();
	s.move();//如果不是虚继承，因为move在俩个父类里面都由，编译器就不知的调用哪个，就是出错，如果是虚继承，多余的那个就会去掉，
}
/*多继承
	虚继承:
		子类有两个以上的父类,而多个父又有共同的父类,那么可以采用虚继承的方式,避免一此重复的函数冲突.
*/
