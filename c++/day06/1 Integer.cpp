#include <iostream>
using namespace std;
class Integer{
	int x;
public:
	Integer(int x=0):x(x){}
	friend ostream& operator<<
		(ostream&o,const Integer&i){
		return o<<i.x;
	}
	//��Ա
	const Integer operator~()const{/*�Ե�ǰ������а�λȡ����������������û�в�
    ������һ��const��Ϊ�˷�ֹ��ʱ������Ϊ��ֵ���֣��ڶ���const��ʾ��ǰ�ĺ���û��
    �޸ĳ�Ա������ֵ*/

		return Integer(~x);//���ص��Ǹ���ʱֵ
	}	
	//ǰ�Ӽ�
	Integer& operator++(){
		x++;
		return *this; //������ص��ǵ�ǰ������*this�������ķ��������ǵ�ǰ���������
	}
	//��Ӽ�
	const Integer operator++(int){//��������Ԫ��ֻ�����ͣ����ã���������ǰ�ӼӺͺ�Ӽ�
		Integer old = *this;//�ѵ�ǰ���󱣴���һ����ʱֵ����
		x++;//��ǰ����+1
		return old;//�������ԭ���Ķ��󣬵��Ǹ���ʱֵ�����ֵ������������
	}
	operator*(){

	}	

	//��Ԫ
/*
	friend const Integer 
		operator~(const Integer&i){
		return Integer(~i.x);
	}	
*/
};
int main()
{
	Integer i1 = 100;
	cout << (~i1) << endl;		
	int x = 10;
	++x = 100;
	cout << "x=" << x << endl;
	++i1;
	cout << "i1=" << i1 << endl;
	++i1 = 200;//i1.operator++() = 200;
	cout << "i1=" << i1 << endl;	
	i1 = 100;
	cout << (i1++) << endl;
	//i1.operator++(int) + 200	
	cout << "i1=" << i1 << endl;
}

