#include <iostream>
using namespace std;
class Human{
public:
	Human(){cout<<"Human()"<<endl;}
	void move(){
		cout << "moving moving" << endl;
	}
};
//��̳�
class Peasant : virtual public Human{
public:
	Peasant(){cout<<"Peasant()"<<endl;}//���캯��
	void work(){
		cout << "more work..." << endl;
	}
};
class FootMan : virtual public Human{//���캯��
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
	public Peasant, public FootMan{//��̳�
public:
	Soldier(){cout<<"Soldier"<<endl;}
};


int main()
{
	Soldier s;
	s.work();
	s.attack();
	s.move();//���������̳У���Ϊmove�������������涼�ɣ��������Ͳ�֪�ĵ����ĸ������ǳ����������̳У�������Ǹ��ͻ�ȥ����
}
/*��̳�
	��̳�:
		�������������ϵĸ���,����������й�ͬ�ĸ���,��ô���Բ�����̳еķ�ʽ,����һ���ظ��ĺ�����ͻ.
*/
