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
	if(pb)cout << "ת���ɹ�" << endl;
	A* pa2 = new C;
//	B* pb2 = (B*)pa2;//�����ǿ��ת�����������ܲ���ת����Ҫת
	B* pb2 = dynamic_cast<B*>(pa2);//���ת���Ǻ����,������ȷ��ָ��(������),���������,���ؿ�(�����쳣)
	if(pb2)cout<<"pb2ת���ɹ�"<< endl;	
}

/*����ת����������Ϣ
	7.1 dynamic_cast:
		1)ֻ�����ж�̬����(�������麯��)
		2)���ڽ������͵�ָ��(������)ת���������͵�ָ��(������).
		3)���ת���Ǻ����,������ȷ��ָ��(������),���������,���ؿ�(���û����쳣)
	7.2 ������������Ϣ
		typeid()���Դ�һ�����������,���ش˶�������͵�������Ϣ.
		*/
