#include <iostream>
using namespace std;
//�ӷ���
class Add{
	int x;
public:
	Add(int x=0):x(x){}
	void operator()(int& r){
		r += x;
	}	
	void operator()(){
		cout<<"����,�������������"<<endl;
	}
};
int main()
{
	Add a = 5;
	int i = 100;
	//a�Ƕ���,����������һ������,�ʳƺ�������
	a(i);//����ú���a,������i
	cout << i << endl;
	a();
}

