#include <iostream>
#include <vector>
#include "../day02/print.h"
using namespace std;
class Integer{
	int x;
public:
	Integer(int x):x(x){
		cout<<"Integer("<<x<<")"<<endl;
	}
	~Integer(){
		cout<<"~Integer("<<x<<")"<<endl;
	}
	friend ostream& operator<<(
		ostream&o, const Integer&i){
		return o<<i.x;
	}
};
int main()
{
	//�������������,��ʵ�ǵ��ÿ������칹���˶���ĸ������뵽������,�����ǰѶ��������������
	vector<Integer> vi;
	Integer i1 = 10;
	Integer i2 = 20;
	vi.push_back(i1);
	vi.push_back(i2);	
	print(vi.begin(), vi.end());
	i1 = 100;
	print(vi.begin(), vi.end());
	cout << "----------------" << endl;
	vector<Integer*> vpi;
	vpi.push_back(&i1);
	vpi.push_back(&i2);
	cout << "----------------" << endl;
	//vector<Integer&> vri;
	//vri.push_back(i1);
}

