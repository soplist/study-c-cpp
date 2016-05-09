#include <iostream>
using namespace std;

class Human{
	string name;
	int power;
public:
	Human(string n="", int p=0)
		:name(n),power(p){
		cout<<"Human(s,i), "<<this<<endl;
	}
	//拷贝构造函数
	Human(const Human& h){
		cout << "Human(const Human&), "
			<< this << endl;
		name = h.name;//意思是把传进来的类的name赋值给自己
		power = h.power;
	}
	~Human()
		{cout<<"~Human(), "<<this<<endl;}
	void show(){
		cout<<name<<","<<power<<endl;
	}

};
void fa(Human h){}
void fb(Human& h){}
int main()
{
	Human h1("Daniel", 100);
	Human h2;
	Human h3 = h1;//Human h3(h1);只要有等于号，就是 把右边的值作为参数传给左边的值
	h3.show();
	cout << "----------------" << endl;
	h2 = h3;//赋值,不会产生新对象
	cout << "----------------" << endl;
	fa(h1);//值传递,会调用拷贝构造,把h1传给h实际上就是把h1拷贝一份给h，h就成新创建对象了，并且h是局部变量，所以当fa这个函数调用完就是就要释放变量，那么对象就会销毁，那么就会调用析构函数
	cout << "----------------" << endl;
	fb(h1);//引用传递（还有指针）,不会调用拷贝构造
	cout << "----------------" << endl;
	Human fc(Human&);//函数的声明
	fc(h1);//调用拷贝,返回的h是个临时值，道理同fa(h1)
	cout << "----------------" << endl;
	Human& fd(Human&);
	fd(h1);//不调用拷贝，
	cout << "----------------" << endl;
	Human h4 = fd(h1);//调用拷贝，赋值的时候导致拷贝构造被调用
//        Human h4&=fd(h1);//不会调用拷贝构造，因为只是把h1的引用返回了回来，就是起了个别名，没有产生新对象
	cout << "----------------" << endl;
	Human& h5 = fd(h1);//不调用，返回的是引用，没有产生新对象
	cout << "----------------" << endl;
}
Human fc(Human& h){ return h; }
Human& fd(Human& h){ return h; }

/*拷贝(复制)构造函数(copy constructor)
	2.1 概念
		当类中没有拷贝构造函数时,编译器会提供一个。函数中提供成员变量的所在拷贝。
	2.2 调用时机
		当用相同类型的对象初始一个新对象时,自动调用拷贝构造函数。
		2.2.1 参数(对象)值传递时,调用拷贝构造
		2.2.2 函数返回临时值(对象),调用拷贝构造
		2.2.3 用相同类型的对象做参数,构造新对象时,调用拷贝构造
		2.2.4 引用传递和地址传递不会调用拷贝构造。
	 总之,凡是有新对象产生的地方,就会调用构造函数,如果是用相同的对象来初始化新对象的,调用的就是拷贝构造函数。
*/

构造函数一旦调用新对象就会产生，新对象产生要经过这三步，第一部，分配内存空间，第二不，如果他的成员变量是个对象，就要构造这个对象，第三步调用构造函数，调用什么样的构造函数取决于用什么参数对他初始化，用h1来初始化就会调用拷贝构造函数（因为符合拷贝构造调用的条件）





