#include <iostream>
#include <cstdlib>
using namespace std;
int i = 10;//ȫ�ֱ���
int main()
{
	int x = 10;//��ջ�з���
	//=========C���ķ��䷽ʽ======
	int* p = (int*)malloc(4);//�ڶ��з����ڴ�ռ䣬malloc���ص���void*���ͣ�c���Ե�д��int*p=malloc(4)����Ϊc�������ͼ���ϸ�����Ҫǿתһ��	
	*p = 100;
	free(p);
	p = NULL;
	//=========C++���==========
	int* p1 = new int;//�ڶ�������ҷ���һ��int�͵Ŀռ�
	*p1 = 123;
	cout << *p1 << endl;
	//free(p1);
	delete p1;	
	//����һ��int�Ϳռ�,��ʼ��Ϊ10
	int* p2 = new int(10);
	cout << *p2 << endl;
	delete p2;	
	//������10��int�Ϳռ�
	int* p3 = new int[10];
	for(int i=0; i<10; i++){
		p3[i] = i;
		cout << p3[i] << ' ';
	}
	cout << endl;
	delete[] p3;//ע��һ��Ҫ[]
	//=====��λ����========
	char buf[100] = {};
	int* p4 = new(buf) int;//��˼�Ǵ�buf����ֲ�������ջ�ռ�)�����һ��int���ڴ�ռ�
	*p4 = 0x41424344;
	for(int i=0; i<4; i++){
		cout << buf[i] << ' ';
	}
	cout << endl;
	//delete p4;
}

