#include <iostream>
using namespace std;
class A{ };
class B{
public:
	operator A(){cout<<"B-->A"<<endl;}//Bת����A
	B(){}//�ղι��캯��
	//Ĭ�������,����Ҫ����ת��ʱ,���캯���ᱻ��ʽ���ö�ʵ������ת��,�������캯��ǰ��explicit��,�˹��ܾ�ʧЧ
	/*explicit*/
	 B(const A& a){cout<<"A-->B"<<endl;}//Aת����B
};
void fa(A a){cout << "fa" << endl;}
void fb(B b){cout << "fb" << endl;}
int main()
{
	B b;
	A a = b;
	B bb = a;//B bb(a);//Ĭ�ϵĵ��ù��캯������ʽ����
	b = a;//Ĭ�ϵĵ��ù��캯������ʽ����
	fa(a);
	fa(b);
	fb(a);//Ĭ�ϵĵ��ù��캯������ʽ����
	fb(b);
}


