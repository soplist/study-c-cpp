#include <iostream>
using namespace std;
class Sample{
	const int ci;
	int& ri;//����
public:
	//����const,���ó�Ա,ֻ���ó�ʼ���б���ɳ�ʼ������Ϊ��ʼ���б����ڷ����ڴ�ռ��ͬʱ��ʼ����
	Sample(const int c, int& r)
		:ci(c),ri(r){ }	
	void show(){
		cout << ci << ',' << ri << endl;
	}
};
int main()
{
	int x = 200;
	Sample s(100, x);
        s.show();
}


