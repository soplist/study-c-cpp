#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class F{
	int n;
	int d;
public:
	F(int n=0, int d=1):n(n), d(d){}
	//����ת�����������
	//����ǰ����ת��double���ͣ������������д����ֵ
	operator double(){ return n*1.0/d; }
	//����ǰ����ת��int����
	operator int()
		{return int(n*1.0/d+0.5);}//��������
	//ת���ַ���
	operator string(){
		char buf[10] = {};
		sprintf(buf, "%d/%d", n, d);
		return buf;//return string(buf),���ص���string,�Զ�����һ��string���͵���ʱ���󣬷��������Զ��İ�char*����ת����string ����
	}
};
void fa(double d){
	cout << "in fa d=" << d << endl;
}
int main()
{
	int x = 3;
	double d;
	d = x;//�Զ�����ת��
	F f1(1,2);
	d = (double)f1;//f1.operator double();
	d = f1;
	fa(f1);	//f1�������ת����double���ͣ���Ϊ�Ѿ��ṩ��ת��double ���͵ĺ���
	int i1 = f1;
	cout << i1 << endl;
	string str = f1;
	cout << str << endl;
}
/*����ת���������û�з���ֵ
   ���캯������������Ҳû�з���ֵ
*/
