#include <iostream>
using namespace std;
//������
class Integer{
	int x;
public: 
	Integer(int x=0):x(x){}//���캯��
	friend ostream& operator<<(
		ostream&o,const Integer&i){
		return o<<i.x;
	}
	friend istream& operator>>(//�������Ͷ��嶼д��������棬���������������ȫ��
		istream&is, Integer&i){
			return is>>i.x;
	}
	friend const Integer operator+//Integer������
	(const Integer&i1, const Integer&i2){
		return Integer(i1.x + i2.x);
	}
/*
	const Integer operator+
		(const Integer&i)const{
		return Integer(x+i.x);
	}
*/
};
int main()
{
	Integer i(100);//�������
	Integer i1 = 100;//�൱��Integer i1(100);
	cout << i1 << endl;
	Integer i2 = i1 + 200;	
	cout << i2 << endl;	
	i2 = 200 + i1;
	cout << i2 << endl;	
}

