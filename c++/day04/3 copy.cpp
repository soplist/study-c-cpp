#include <iostream>
using namespace std;
class Date{
	int y,m,d;
public:
	Date(int y=0, int m=0, int d=0)
		:y(y),m(m),d(d){
		cout<<"Date(i,i,i), "<<this<<endl;
	}
	~Date()
		{cout<<"~Date(), "<<this<<endl;}
};
class Emp{
	string name;//name�Ǹ�����Ҫ�������
	Date* birth;
	double salary;
public:
	Emp(string n, int y, int m, int d, 
		double s):name(n),salary(s){
		birth = new Date(y,m,d);		
		cout << "Emp(s,i,i,i,d), " 
			<< this << endl;
	}
	~Emp(){
		delete birth;//��ֹ�ڴ�й¶
		birth = NULL;
		cout <<"~Emp(), "<<this<<endl;
	}
	//�ṩ�������캯��,��ɶ�������
	Emp(const Emp& e){
		cout<<"Emp(const Emp&)"<<endl;
		name = e.name;
		birth = new Date(*e.birth); //e.birth��һ��ָ�룬�������У���������Ƕ�����
		salary = e.salary;
	}		
};

int main()
{
	Emp e("Daniel",1980,2,25,160000);
	Emp e2 = e;	
}
//������Ҫʵ�����ʱ,һ�������еĳ�Ա������ָ��, ��ָ���˶��е��ڴ�,�͵��ṩ�Զ����������캯��,������Ĭ�ϵĿ������캯���Ѿ���������Ҫ��
