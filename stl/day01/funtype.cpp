#include <iostream>
using namespace std;
template <typename T> void type(T x){
	cout << typeid(T).name() << endl;
}
template <typename T, typename U> T add(T a, U b){
	return a + b;
}

template <typename T> T sub(T a, T b){}
template <typename T> T get(){
	return T();
}
template <typename T, int n>
void print(T a[]){ }
template <typename T, typename U>
T cast(U u){ return T(u);}
int main()
{
	int a; type(a);
	double b; type(b);
	string s; type(s);
	int r = add(1, 2);	
	double d = add(1.2, 2.3);
	add(2.3,1);	
	//ʵ�α��õ���Ϣ��ì��
	sub<double>(2.3, 1);	
	//��������û�г��ַ�������
	r = get<int>();
	cout << r << endl;
	int aa[] = {1,2,3};
	//��ģ�����������ͨ���Ͳ���ʱ
	print<int,5>(aa);
	double d1 = 3.14;
	//���صķ���û�г����ڲ�����
	r = cast<int, double>(d1);	
}

