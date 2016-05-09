#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class Date{
public:
	int y,m,d;
	Date(int y=0, int m=0, int d=0)
		:y(y),m(m),d(d){
		cout << "Date(i,i,i)" << endl;
	}
	~Date(){cout<<"~Date()"<<endl;}
	string toString(){//toString���������������յ��ַ���
		char buf[20] = {};
		sprintf(buf,
			"%04d-%02d-%02d",y,m,d);
		return buf;
	}
};

class Emp{
	string name;
	Date birth;
public:
	Emp(string n=""):name(n){
		cout << "Emp(string)" << endl;
	}	
	~Emp(){cout << "~Emp()" << endl;}
	void show(){
		cout << name << "," 
			<< birth.toString() << endl;
	}
};

int main()
{
	//��ջ�й������
	Date d;
	Date d2(2012,9,23);//û�в����Ͳ�Ҫд���ţ��в����ſ���Щ����
	Date* pd;
	Date& rd = d;//���ṹ�����
	pd = new Date();//�ڶ��й������	
	cout << pd->toString() << endl;//pd->toString�ȼ���(*pd).toString()
	delete pd;
	pd = NULL;//��ָ����������ָ�븳ֵΪNULL,��Ȼ���ָ���������ָ��	
	pd = new Date(2012,12,21);
	cout << pd->toString() << endl;
	delete pd;
	cout << "------------------" << endl;
	Date* pd2=(Date*)malloc(sizeof(Date));
	pd2->y = 2013;
	pd2->m = 1;
	pd2->d = 1;
	cout << pd2->toString() << endl;
	free(pd2);
	cout << "------------------" << endl;
	Emp* pe = new Emp("Daniel");//�����Ա�����Ƕ����ȹ������Ȼ����ù��캯��
	pe->show();
	delete pe;
	cout << "------------------" << endl;
	Emp* pe2 = (Emp*)malloc(sizeof(Emp));//malloc ֻ�ܷ����ڴ�ռ䣬����������û��
	pe2->show();
	free(pe2);
	cout << "------------------" << endl;
}
/*1.1 new �� malloc������
		1)mallocֻ��������ڴ�ռ�,��������ö���Ĺ��캯��,��������ʱ,Ҳ�����������������
		2)malloc��Ҫ��������ת��,��new�Ѿ�������ת�����ˡ�*/
