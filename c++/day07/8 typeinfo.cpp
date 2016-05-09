#include <iostream>
using namespace std;
class A{
public: virtual void show(){}
};
class B : public A{};
class C : public A{};
class D : public B{};

void type(A* pa){
	if(typeid(*pa) == typeid(B)){//typeid(*pa)返回类型信息，如果返回时类型信息是B类型，那么就指向B
		cout << "B" << endl;
	}else if(typeid(*pa)==typeid(C)){
		cout << "B" << endl;
	}else if(typeid(*pa)==typeid(D)){
		cout << "D" << endl;
	}	
}
int main()
{
	A* pa = new B;
	type(pa);//这个指针指向的是B类型
	A* pb = new D;
	type(pb);//这个指针指向D类型
}

//运行期类型信息
		typeid()可以传一个对象或类型,返回此对象或类型的类型信息.
		
