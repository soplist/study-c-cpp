#include <iostream>
using namespace std;
//����, ����, ����, ����, ��ҹ, ����
/*
human is a creature
orc is a creature
footman is a human
*/
//������
class CRE{
	int HP;//����ֵ
	int DEF;//����
	int ACT;//����
public:
	CRE(int h=100, int d=100, int a=100)//��Ĭ��ֵ�Ĺ��캯�������ղι��캯�������Ա��ղι��캯�����ã����û�и�Ĭ��ֵ����ô��������Ҫ������
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
	Human(int h=100, int d=100, int a=100)//Ĭ��ֵ���Բ��������ǹ�������ʱ���Ҫ������
	:CRE(h, d, a){//�ڳ�ʼ���б���ֱ�ӹ���һ�������������࣬�����ͻ���ø������������������Ĺ��캯���������д�������͵���û�в����Ĺ��캯��
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
	//��������,�����к������͸����е���ͬ���ͻ��ȵ��������
	void move(){
		cout << "Peasant move" << endl;
	}
	//��������
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
	p1.attack("MK");//���������
	p1.Human::attack();//ָ�����ø����
	p1.work();	
	p1.Human::move();//���ø����м̳�����
	cout << "-------------" << endl;
}
/*��������Ǹ���Ķ����һ���֣������������ʱ��Ҫ���츸����󣬵����������ʱ������������������У���ô�ʹ���������е��ã�������������û�У��ʹ����ĸ���������ң����������û�У���ô�ʹӸ���ĸ���ĸ������ң�֪������Ϊֹ������ұ��˶��Ҳ�������ô�������ͻᱨ��.
һ������£�Ĭ�ϵ����๹�캯�������Ĭ�ϵĸ����Ĭ�Ϲ��캯��
*/
