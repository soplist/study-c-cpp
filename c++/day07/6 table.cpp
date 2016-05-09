#include <iostream>
#include <cstring>
using namespace std;
class A{
public:
	int x;
	virtual void show(){ 
		cout << "in A x=" << x << endl;
	}	
};
class B : public A{
public:
	virtual void show(){
		cout << "in B " << endl;
	}
};
class C : public A{
public:
	virtual void show(){
		cout << "in C " <<endl;
	}
};
int main()
{
	cout << sizeof(A) << endl;
	A* pa = new B;
	A* pb = new C; 
	pa->show();//		
	memcpy(pa, pb, 4);//memcp�ڴ濽����������pb���濽���ĸ��ֽڵ�pa���棬��paָ��Ķ���ָ��pbָ��Ķ���	
	pa->show();
}

/*��̬��ʵ��
�麯����
	C++ͨ���麯������ʵ�ֶ�̬.
	��������麯��,��ô����֧�ֶ�̬.�������Ŀ�ʼ4���ֽڷŵ����麯����ĵ�ַ.
	��������ʱ,��ͨ��ָ������õ��ô˶�����麯��ʱ,�ȴӶ����л�ȡ�麯����,�ٴӱ��в�Ҫ���õľ��庯���ĵ�ַ,�����ô˺���.�Ӷ�ʵ�ֶ�̬.
	����C++�еĶ�̬������һЩϵͳʱ�����Դ.������ϵͳ��Ч��Ҫ��ǳ���,�ɿ��ǲ�ʹ�ö�̬.*/
