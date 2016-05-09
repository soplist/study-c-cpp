#include <iostream>
using namespace std;
class A{
public: virtual void show(){}
};
class B : public A{};
class C : public A{};
class D : public B{};

int main()
{
	A* pa = new B;
//	B* pb = (B*)pa;		
	B* pb = dynamic_cast<B*>(pa);	
	if(pb)cout << "转换成功" << endl;
	A* pa2 = new C;
//	B* pb2 = (B*)pa2;//这个是强制转换，不管你能不能转，都要转
	B* pb2 = dynamic_cast<B*>(pa2);//如果转换是合理的,返回正确的指针(或引用),如果不合理,返回空(或抛异常)
	if(pb2)cout<<"pb2转换成功"<< endl;	
}

/*类型转换及类型信息
	7.1 dynamic_cast:
		1)只用于有多态的类(类中有虚函数)
		2)用于将父类型的指针(或引用)转换成子类型的指针(或引用).
		3)如果转换是合理的,返回正确的指针(或引用),如果不合理,返回空(引用会抛异常)
	7.2 运行期类型信息
		typeid()可以传一个对象或类型,返回此对象或类型的类型信息.
		*/
