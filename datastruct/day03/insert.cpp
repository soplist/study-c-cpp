#include <iostream>
#include <algorithm>
using namespace std;
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
//����
void sort(int* a, int n){
	for(int i=1; i<n; i++){
		int t = a[i];//Ҫ���������
		int j;//�����λ�� 
		for(j=i; j>0&&a[j-1]>t; j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
		cout << "��" << i << "��:";
		print(a, n);
	}
}
int main()
{
	int a[10] = {3,7,6,8,0,9,2,5,1,4};
	cout << "����ǰ:";
	print(a, 10);
	sort(a, 10);
	cout << "�����:";
	print(a, 10);
}

