#include <iostream>
using namespace std;
class A{
public: virtual void show(){}
};
class B : public A{};
class C : public A{};
class D : public B{};

void type(A* pa){
	if(typeid(*pa) == typeid(B)){//typeid(*pa)����������Ϣ���������ʱ������Ϣ��B���ͣ���ô��ָ��B
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
	type(pa);//���ָ��ָ�����B����
	A* pb = new D;
	type(pb);//���ָ��ָ��D����
}

//������������Ϣ
		typeid()���Դ�һ�����������,���ش˶�������͵�������Ϣ.
		
