#include <iostream>
#include <algorithm>
using namespace std;
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
//选择
void sort(int* a, int n){
	for(int i=0; i<n-1; i++){
		int k = i;//保存最小数的下标
		for(int j=i+1; j<n; j++){
			if(a[j]<a[k]) k = j;
		}
		if(k!=i) swap(a[k], a[i]);
		cout << "第" << i << "次:";
		print(a, n);
	}
}
int main()
{
	int a[10] = {3,7,6,8,0,9,2,5,1,4};
	cout << "排序前:";
	print(a, 10);
	sort(a, 10);
	cout << "排序后:";
	print(a, 10);
}

