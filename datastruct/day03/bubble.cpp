#include <iostream>
using namespace std;
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
//ð��
void sort(int* a, int n){
	for(int i=0; i<n-1; i++){
		bool flag = true;
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = false;
			}
		}
		if(flag)break;
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

