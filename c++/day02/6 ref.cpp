#include <iostream>
using namespace std;
//���������൱�ڷ��ر���(x)����
int& fa(){
	static int x = 10;
	return x;
}

int main()
{
	cout << fa() << endl;
	int& r = fa();//int& r = x;����fa()���ص���x�����ã�����һ��int�͵�����������x�����ã��൱���ڸ�x�������r
	r++;//x++;
	cout << fa() << endl;//cout<<x<<endl;
	int r2 = fa();//int r2 = x;��ֵ����r2�������㣬����Ӱ��x
	r2++;
	cout << fa() << endl;
	fa() = 100;//x=100;
	cout << fa() << endl;



}

