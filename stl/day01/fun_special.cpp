#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//函数模板
template <typename T>
void print(T* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
void print(char* a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
//偏特化,相当于又写了一个函数模板
template <typename T> void print(T* a[], int n){
	for(int i=0; i<n; i++){
		cout << *a[i] << ' ';
	}
	cout << endl;
}
//函数模板
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
void sort(char* a[], int n){
	for(int i=1; i<n; i++){
		char* t = a[i];
		int j; 
		for(j=i; j>0&&strcmp(a[j-1],t)>0;
			 j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
	}
}
//偏特化的函数模板
template <typename T> 
void sort(T* a[], int n){
	for(int i=1; i<n; i++){
		T* t = a[i];
		int j; 
		for(j=i; j>0&&*a[j-1]>*t; j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
	}
}

int main()
{
	char* cs[] = {
		"abc", "aaa", "bca", "abb", "cba"
	};
	sort(cs, 5);
	print(cs, 5);
	int* is[] = {
		new int(3),new int(2),new int(5),
		new int(4), new int(8)
	};
	sort(is, 5);
	print(is, 5);
	double* ds[] = {
		new double(2.1),new double(1.2),
		new double(4.3),new double(3.4),
		new double(5.6)};
	sort(ds, 5);
	print(ds, 5);
}

