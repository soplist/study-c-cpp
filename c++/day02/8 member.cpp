#include <iostream>
#include <cstdio>
using namespace std;
struct Date{
	int year;
	int month;
	int day;
};

int main()
{
	struct Date d = {2012, 12, 21};
	cout << &d.year << endl;	
	cout << &d.month << endl;	
	cout << &d.day << endl;	
	//��Աָ��,C++�е�����ָ��
	//::���������
	int Date::* p1 = &Date::year;//&Date::year;�ĵ�ַ��һ����Ե�ַ0��������������int Date::*����
	int Date::* p2 = &Date::month;//&Date::month;��Ե�ַΪ4
	int Date::* p3 = &Date::day;//&Date::day;��Ե�ַΪ8
	cout << (d.*p1)<<"-"<<(d.*p2)
			<< "-" << (d.*p3) << endl;	
/*
	cout << p1 << endl;//cout ��ӡ���ĺ����ĵ�ַ�Ǹ�true��true����1
	cout << p2 << endl;
	cout << p3 << endl;
	cout << main << endl;	
	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
*/
	cout << "---------------" << endl;
	Date ds[3] = {
		{2012,12,21},{2010,9,21},{2011,9,3}
	}; 
	void print(Date* ds,int n,int Date::*p);
	print(ds, 3, &Date::day); 
}
void print(Date* ds,int n,int Date::*p){
	for(int i=0; i<n; i++){
		//cout << ds[i].*p << endl;
		cout << (ds+i)->*p << endl;
	}
} 
/*
��Աָ����һ����Ե�ַ
�ṹ���еĳ�Ա(���������ͺ���)����Ե�ַ��ȡ��ʽ
&�ṹ������::��Ա
������Աָ�����
��Ա���� �ṹ������::*ָ�������
ͨ����Աָ����ʽṹ��Ա
�ṹ����.*ָ�������
�ṹ��ַ->*ָ�������
*/
