#include <iostream>
using namespace std;

int main()
{
	double d = 3.14159;
	int i = (int)d;//��c�����п��ԣ���c++�л��о��棬һ��������Ǵ��޵ģ�ֻ��doubleת��int���棬Ϊ�˼���c
	cout << i << endl;	
	i = int(d);
	cout << i << endl;	
	i = static_cast<int>(d);
	cout << i << endl;	
	void* p = malloc(40);
	int* pi = static_cast<int*>(p);
	//��һ���ľ�̬���ͼ��
	//double* pd = static_cast<double*>(pi);int*����ת����double*
	//��ͬ���͵�ָ��֮��ʹ�õ�ת����ʽ
	double* pd = reinterpret_cast<double*>(pi);
	//ȡ��cv���� 
	const volatile int ci = 100;
	//const int* pci = &ci;
	int* pci = const_cast<int*>(&ci);
	*pci = 200;
	cout << ci << endl;//��������Ϊci�ǳ�������ӡci���Ǵ�ӡ100����һ��volatile ����˼�����������һ����ʱ���Ըı��ֵ	�����ʱ��ͻ��ӡ200
       cout<<*pci<<endl;	
}

/*
static_cast<����>()
ת��ʱ����̬��飬���ڱ���ʱ����
void*������ָ���ת��
reinterprect_cast<����>()
����ǿת�κ����͵�ָ��
������ǿת��ָ�룬ָ��ǿת������
const_cast<����>()
ȥ��cv���� const volatile
dynamic_case<����>()
��̬ת��
*/
