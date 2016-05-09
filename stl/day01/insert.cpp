#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
void print(T* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
template <typename T>
void sort(T a[], int n){
	for(int i=1; i<n; i++){
		T t = a[i];
		int j; 
		for(j=i; j>0&&a[j-1]>t; j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
	}
}
int main()
{
	int a[10] = {3,7,6,8,0,9,2,5,1,4};
	sort(a, 10);	
	print(a, 10);
	double b[5]={2.2,1.1,5.4,3.3,6.2};
	sort(b, 5);	
	print(b, 5);
	string strs[] = {"abc", "aaa", "bca", "abb", "cba"};
	sort(strs, 5);
	print(strs, 5);
}

