#include <iostream>
#include <string>
using namespace std;
class Person{
	string name;
	int age;
	bool gender;
public:
	Person(string name="",int age=0,
		bool gender=true){
		this->name = name;
		this->age = age;
		this->gender = gender;
		cout << "Person(s,i,b)" << endl;
	}
	void show(){
		cout << name<< ',' << age << ',' <<
			(gender?"��":"Ů") << endl;
	}	
	//��������
	~Person(){
		cout << "~Person()" << endl;
	}
};
int main()
{
	cout << "-------------------\n";
	if(1){//�߼���
		Person p("Daniel", 30, true);//���ù��캯���������
		p.show();
	}//p ��if���ǰ�������������
	cout << "-------------------\n";
	Person* pi = 
		new Person("Guodh",31,true);//�ڶ����湹�����	
	delete pi;//֮�������������
}
//��������û�в��������Ծ�û�����أ�һ������������������ֻ��һ�������������ڶ�������ǰ�Զ�����
