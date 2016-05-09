#include <iostream>
using namespace std;
class Human{
public:
	//普通函数不具有多态性
	void move(){
		cout<<"moving moving"<<endl;	
	}
	//虚函数,具有多态性
	virtual void attack(){
		cout<< "attack" << endl;
	}
};
class FootMan : public Human{
public:
	//名字隐藏（只要函数名字一样就行）
	void move(){
		cout << "action" << endl;
	}	
	//函数的覆盖（1)函数名相同 2参数列表相同 3 返回值相同 
	virtual void attack(){//在函数的前面加virtual就是虚函数，他最大的特性就是具有多态性
		cout << "FootMan attack" << endl;
	}
};
class RifleMan : public Human{
public:
	void move(){
		cout << "OOOOK" << endl;
	}
	virtual void attack(){
		cout << "Fireeeeee" << endl;
	}
};
class Peasant : public Human{
public:
	void move(){
		cout<<"more work" << endl;
	}	
	void work(){
		cout << "work work" <<endl;
	}
};
int main()
{
	Human* ph = new FootMan;//父类的指针指向子类的对象,一个指针在运行期间，可以指向任何地方，编译器在编译的时候并不知道ph是指向子类的对象
	ph->move();//编译期绑定  （在不是多态的情况下调用的是父类的函数，调用哪个函数取决于编译器，编译器在编译这段代码的时候，检查了一下，ph是Human类型的指针，通过父类型的指针调用move自然就是父类的）
	ph->attack();//运行期绑定	（父类里面的attact函数是虚函数，子类里面的attack也是虚函数，就会调用子类里面的函数
	delete ph;
	ph = new RifleMan;
	ph->move();//编译期绑定
	ph->attack();//运行期绑定
	delete ph;
	cout<<"--------------------"<<endl;
	FootMan fm;//构造对象
	RifleMan rm;
	Human& rh = fm;
	rh.move();//父类
	rh.attack();//子类
	cout<<"--------------------"<<endl;
	Human* ph2 = new Peasant;//编译器编译时首先看ph是Human类型，所以就先从Human 类里面找，如果函数不是虚函数，就调用父类里面的，如果是虚函数，就调用子类里面的
	ph2->move();
	ph2->attack();
	//调用父类中没有的函数不能通过编译
	//ph2->work();	
}
/*一个变量,多种形态
	用一个父类的指针(或引用)指向一个子类的对象时,当通过该指针(或引用)调用函数时,真正调用的函数是子类的函数.
	多态的目的:写出更通用的程序来*/
