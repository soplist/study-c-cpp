#include <iostream>
using namespace std;
//��������Ԫ,Ϊ����ǰ����,++,--����ʱ����
void fa(int){
	cout << "fa" << endl;
}
/*
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
void print(int* a, int n, char c){
	for(int i=0; i<n-1; i++){
		cout << a[i] << c;
	}
	cout << a[n-1] << endl;
}
*/
void print(double* a, int n){

}
void print(int* a, int n=10, 
		char c=' ',bool f=false){//�������Դ�Ĭ��ֵ�������������������Ĭ��ֵ��Ĭ��ֵ�ĸ����Ǵ���������ģ�����ұߵ�û�У���ߵĲ����Դ����������
	if(f)cout << "[";
	for(int i=0; i<n-1; i++){
		cout << a[i] << c;
	}
	cout << a[n-1] <<(f?"]":" ")<< endl;
}

//��������,�����Ǹ�����,�᲻���������ȡ���ڱ�����
inline void fb(){

}

int main()
{
	fa(10);
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	print(a, 10);
	print(a, 10, ',');
	print(a, 10, ',', true);
	print(a);
}
/*�����Ĳ���֧����Ԫ
��Ԫ��һ��û�в������Ĳ�������Ҫ��Ϊ�˺�����������Լ���ǰ����
�����Ĳ�������ָ��Ĭ��ֵ��������ʱû�д��Σ�����Ĭ��ֵ���к������á�
��Ĭ��ֵ���βα��뿿�ң������Ͷ���ֿ�ʱ��Ĭ��ֵ������������ָ���������в���ָ����
*/

