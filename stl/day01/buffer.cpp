#include <iostream>
using namespace std;
//n不是类型参数,而普通参数,这种参数只能看做常量来使用
template <typename T=int, int n=10> 
class Buffer{
public:
	explicit Buffer():sz(){}
	//n在程序运行期间不可改变
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
	//普通模板参数只能传常量值,不能传变量值
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

