#include <iostream>
using namespace std;
//n�������Ͳ���,����ͨ����,���ֲ���ֻ�ܿ���������ʹ��
template <typename T=int, int n=10> 
class Buffer{
public:
	explicit Buffer():sz(){}
	//n�ڳ��������ڼ䲻�ɸı�
	void expand(){ n = 2*n;}//ERROR
	int capacity() { return n; }//OK
	void push(T d){buf[sz++]=d;}
private:
	T buf[n];	
	int sz;
};
int main()
{
	Buffer<int, 10> bufi10;
	//bufi10.expand();	
	//��ͨģ�����ֻ�ܴ�����ֵ,���ܴ�����ֵ
	const int x = 100;
	Buffer<string, x> bsi100;
	cout << bsi100.capacity() << endl;	
	Buffer<int, 20> bufi20;
	
	cout << 
		(typeid(bufi10)==typeid(bufi20)) 
		<< endl;	
	Buffer<int> bi;
	cout << bi.capacity() << endl;
	Buffer<int, 123> bi123;
	cout << bi123.capacity() << endl;
	
	Buffer<> buffer;
	buffer.push(100);
}

