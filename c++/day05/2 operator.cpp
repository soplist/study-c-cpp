#include <iostream>
using namespace std;
//������
class F{
	int n;//����
	int d;//��ĸ
public:
	F(int n=0, int d=1):n(n),d(d){}
	//������Ԫ  ���Է���˽�г�Ա
	friend ostream& 
		operator<<(ostream&,const F&);//,const F& ������Ҫ��ӡĳһ�����������ʱ����Ҫ����һ�ݹ�������ӡ�������Ƿݣ�
                                                                                           //  ǰ���const˵�����ȿ��Դ�ֻ���� ����Ҳ���Դ���ֻ���Ĵ�ӡ
	friend istream&
		operator>>(istream&,F&);//���F�������� f���Ǹ����Ƴ�������ʱ���󣬲��Ƕ������������ֵ�͸������ʱ����ģ���������ɺ���ͷ���
};
ostream&operator<<(ostream&o,const F&f){//o��������ostream&  ostream�Ŀ���������˽�еģ�����Ҫ������
	o<<f.n<<'/'<<f.d;//cout ����o
	return o;//���ر����������Ϳ��������Ĵ�ӡ
}
istream&operator>>(istream&i,F&f){
	char c;
	i>>f.n>>c>>f.d;//cin ����
	return i;
}

int main()
{
	int x = 100;
	cout << x << endl;//cout���࣬cout��ostream���ͣ�operator�Ǻ�������ӡxʵ�����ǵ���cout���������operator������cout.operator(),��x��Ϊ��������ȥ
	cout.operator<<(x).operator<<(endl);//operator<< ���صľ��ǵ�ǰ����cout,������ӡ��x֮�󷵻�cout,Ȼ����cout������ӡendl;
	cout << endl;//
	F f(1,2);
	cout << f << endl;//f��������F����cout.operator()���������غ�������û��������ͣ����Բ��ܴ�ӡf
     //cout.operator<<x   /cout��ostream��Ķ���Ҫ����cout�ܴ�ӡf��Ҫ���޸�ostream����࣬����ostream�ǲ����޸ĵ�
    //   operator<<(cout,f)
	operator<<(cout,f).operator<<(endl);//cout����ostream& o�����ã�����o����cout��cout����o
	F f2(3,4);
	cout << "f2=" << f2 << endl;
	F f3(3,5);
	cout << "f3=" << f3 << endl;
	cout << "----------------" << endl;
	cout << "������һ������:";
	cin >> x;//cin ==> istream
	cout << "������һ������:";
	cin >> f;//operator>>(cin,f);
	cout << "f=" << f << endl;
}

/*
��c++�����κ�һ����������Ǻ�������ӡһ������ʵ���Ͼ��ǵ����������
*/

