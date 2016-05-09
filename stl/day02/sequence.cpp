//序列式容器的共性
#include <iostream>
#include <deque>
using namespace std;
#include "print.h"
int main()
{
	deque<int> di(5, -1);
	cout << di.size() << endl;
	print(di.begin(), di.end());	
	di.insert(di.end(), 1);
	di.insert(di.end(), 3, 2);
	print(di.begin(), di.end());	
	int a[5] = {4,5,6,7,8};
	di.insert(--di.end(), a, a+5);		
	print(di.begin(), di.end());	
	di.assign(3, 100);
	print(di.begin(), di.end());	
	di.assign(a, a+5);
	print(di.begin(), di.end());	
	di.resize(8, 5);
	print(di.begin(), di.end());	
	di.resize(5);
	print(di.begin(), di.end());	
	di.front() = 123;
	di.back() = 456;
	print(di.begin(), di.end());	
	di.push_back(888);
	print(di.begin(), di.end());	
	di.pop_back();
	print(di.begin(), di.end());	
}

