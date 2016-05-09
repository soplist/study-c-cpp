//list的个性
#include <iostream>
#include <list>
using namespace std;
#include "print.h"
/*
template <typename T> class my_greater{
public:
	bool operator()(T a, T b){
		return a > b;
	}
};
*/
int main()
{
	int a[8] = {3,2,5,8,6,8,8,5};
	list<int> li(a, a+8);
	print(li.begin(), li.end());
	li.push_back(9);
	li.push_front(1);
	print(li.begin(), li.end());
	li.pop_front();
	li.pop_back();
	print(li.begin(), li.end());
	li.remove(5);	
	print(li.begin(), li.end());
	li.unique();
	print(li.begin(), li.end());
	li.sort(/*less<int>()*/);
	print(li.begin(), li.end());
	li.sort(greater<int>());
	print(li.begin(), li.end());
	li.reverse();
	print(li.begin(), li.end());
	list<int> li2(3, 10);
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
	li.splice(--li.end(), li2);		
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
	li2.splice(
		li2.begin(),li,li.begin());
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
	li2.splice(li2.end(), li, 
		li.begin(), ++++++li.begin());
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
	//如果归并前,两个list是排好序的,那么归并后一定也是排好序的
	li.merge(li2);//归并
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
	
	li2.assign(2, 9);
	li.sort();
	li2.sort();
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
	li.merge(li2);	
	cout << "--------------" << endl;
	print(li.begin(), li.end());
	print(li2.begin(), li2.end());
}





