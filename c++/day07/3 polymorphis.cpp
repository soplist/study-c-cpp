#include <iostream>
using namespace std;
class Human{
public:
	//��ͨ���������ж�̬��
	void move(){
		cout<<"moving moving"<<endl;	
	}
	//�麯��,���ж�̬��
	virtual void attack(){
		cout<< "attack" << endl;
	}
};
class FootMan : public Human{
public:
	//�������أ�ֻҪ��������һ�����У�
	void move(){
		cout << "action" << endl;
	}	
	//�����ĸ��ǣ�1)��������ͬ 2�����б���ͬ 3 ����ֵ��ͬ 
	virtual void attack(){//�ں�����ǰ���virtual�����麯�������������Ծ��Ǿ��ж�̬��
		cout << "FootMan attack" << endl;
	}
};
class RifleMan : public Human{
public:
	void move(){
		cout << "OOOOK" << endl;
	}
	virtual void attack(){
		cout << "Fireeeeee" << endl;
	}
};
class Peasant : public Human{
public:
	void move(){
		cout<<"more work" << endl;
	}	
	void work(){
		cout << "work work" <<endl;
	}
};
int main()
{
	Human* ph = new FootMan;//�����ָ��ָ������Ķ���,һ��ָ���������ڼ䣬����ָ���κεط����������ڱ����ʱ�򲢲�֪��ph��ָ������Ķ���
	ph->move();//�����ڰ�  ���ڲ��Ƕ�̬������µ��õ��Ǹ���ĺ����������ĸ�����ȡ���ڱ��������������ڱ�����δ����ʱ�򣬼����һ�£�ph��Human���͵�ָ�룬ͨ�������͵�ָ�����move��Ȼ���Ǹ���ģ�
	ph->attack();//�����ڰ�	�����������attact�������麯�������������attackҲ���麯�����ͻ������������ĺ���
	delete ph;
	ph = new RifleMan;
	ph->move();//�����ڰ�
	ph->attack();//�����ڰ�
	delete ph;
	cout<<"--------------------"<<endl;
	FootMan fm;//�������
	RifleMan rm;
	Human& rh = fm;
	rh.move();//����
	rh.attack();//����
	cout<<"--------------------"<<endl;
	Human* ph2 = new Peasant;//����������ʱ���ȿ�ph��Human���ͣ����Ծ��ȴ�Human �������ң�������������麯�����͵��ø�������ģ�������麯�����͵������������
	ph2->move();
	ph2->attack();
	//���ø�����û�еĺ�������ͨ������
	//ph2->work();	
}
/*һ������,������̬
	��һ�������ָ��(������)ָ��һ������Ķ���ʱ,��ͨ����ָ��(������)���ú���ʱ,�������õĺ���������ĺ���.
	��̬��Ŀ��:д����ͨ�õĳ�����*/
