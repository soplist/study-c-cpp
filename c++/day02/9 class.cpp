#include <iostream>
using namespace std;
struct Dog{
	//��Ա����
	string name;
	string bread;
	int age;
	//��Ա����
	void eat(){
		cout << "����" << endl;
	}
	void sleep(){
		cout << "��˯" << endl;
	}
	void grow(){ age++; }
	void show(){
		cout << "�ҽ�" << name << ",��"
			<< bread << "Ʒ��" << ",����"
			<< age << "����" << endl;
	}
};
int main()
{
	//��������һ������,�൱�ڹ���һ������
	Dog d;//��ջ�й���
	d.name = "����";
	d.bread = "̩��";
	d.age = 2;
	d.eat();
	d.sleep();
	d.grow();
	d.show();	
	Dog* pd = new Dog;//�ڶ��й���
	pd->name = "Mu";
	pd->bread = "��ë";
	pd->age = 1;
	pd->eat();
	pd->sleep();
	pd->grow();
	pd->show();	
	delete pd;//�ǵ�Ҫ�ͷ�
	pd = NULL;

	//����ͨ��������ó�Ա����,û�ж����޷����ó�Ա����
	//Dog::eat();




}
//�������һ������

