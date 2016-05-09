#include <iostream>
#include <algorithm>
using namespace std;
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
//插入
void sort(int* a, int n){
	for(int i=1; i<n; i++){
		int t = a[i];//要插入的数据
		int j;//插入的位置 
		for(j=i; j>0&&a[j-1]>t; j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
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

