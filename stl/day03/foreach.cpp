#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include "../day02/print.h"
void add10(int& x){ x += 10; }
template <typename T, typename U>
void foreach(T b, T e, U f){
	while(b!=e){f(*b++);}
}
//º¯Êý¶ÔÏó
class add{
	int n;
public:
	add(int n):n(n){}
	void operator()(int& x){ x += n;}	
};
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	for_each(a, a+10, add(3));
	print(a, a+10);
	for_each(a, a+10, add(1));
	print(a, a+10);
	vector<int> v(a, a+10);
	for_each(v.begin(),v.end(),add10);	
	print(v.begin(), v.end());	
		
}

