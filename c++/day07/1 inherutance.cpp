#include <iostream>
using namespace std;
//生物, 人族, 兽族, 不死, 暗夜, 步兵
/*
human is a creature
orc is a creature
footman is a human
*/
//生物类
class CRE{
	int HP;//生命值
	int DEF;//防御
	int ACT;//攻击
public:
	CRE(int h=100, int d=100, int a=100)//有默认值的构造函数包括空参构造函数，可以被空参构造函数调用，如果没有给默认值，那么调用数就要传参数
		:HP(h),DEF(d),ACT(a){
		cout<<"CRE(i,i,i), "<<this<<endl;
	}
	~CRE(){cout<<"~CRE(), "<<this<<endl;}
	int getHP(){return HP;}
	void setHP(int HP){this->HP=HP;}
	int getDEF(){return DEF;}
	int getACT(){return ACT;}	
	void move(){
		cout<<"CRE moving moving"<<endl;
	}	
	void attack(){
		cout<<"CRE attttacccck.."<<endl;
	}
};
class Human : public CRE{
public:
	Human(int h=100, int d=100, int a=100)//默认值可以不给，但是构造对象的时候就要传参数
	:CRE(h, d, a){//在初始化列表中直接构造一个父类对象给子类，这样就会调用父类里面有三个参数的构造函数，如果不写参数，就调用没有参数的构造函数
		cout<<"Human(), "<<this<<endl;
	}
	~Human(){
		cout<<"~Human(), "<<this<<endl;
	}
};
class Peasant : public Human{
public:
	Peasant(int h=50, int d=20, int a=10)
	:Human(h, d, a){
		cout<<"work work.. ,"<<this<< endl;
	}	
	~Peasant(){
		cout<<"OH,I'll dead."<<this<<endl;
	}
	//名字隐藏,子类中函数名和父类中的相同，就会先调用子类的
	void move(){
		cout << "Peasant move" << endl;
	}
	//名字隐藏
	void attack(string name){
		cout << "Peasant attacked "
			<< name << endl;
	}
	void work(){
		cout<<"More Work..."<<endl;
	}
};

int main()
{
	Human h;
	h.move();
	h.attack();	
	cout << h.getHP() << endl;
	cout << "-------------" << endl;
	Peasant p1;
	p1.move();
	p1.attack("MK");//调用子类的
	p1.Human::attack();//指定调用父类的
	p1.work();	
	p1.Human::move();//调用父类中继承来的
	cout << "-------------" << endl;
}
/*子类对象是父类的对象的一部分，构造子类对象时先要构造父类对象，调用子类对象时，如果如果子类对象中有，那么就从子类对象中调用，如果子类对象中没有，就从他的父类对象中找，如果父类中没有，那么就从父类的父类的父类中找，知道找着为止，如果找遍了都找不到，那么编译器就会报错.
一般情况下，默认的子类构造函数会调用默认的父类的默认构造函数
*/
