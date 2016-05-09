//关联式容器的共性
#include <iostream>
#include <set>
using namespace std;
#include "print.h"
int main()
{
	int a[10] = {1,5,6,8,8,0,5,8,3,7};
	multiset<int> mi(a, a+10);
	print(mi.begin(), mi.end());	
	multiset<int>::iterator it;
	it = mi.find(6);	
	if(it==mi.end()){
		cout << "not found" << endl;
	}else{
		cout << "found "<< *it << endl;
	//不能通过迭代器直接修改关联式容器中的值
		//*it = 60;
		mi.erase(it);//标准容器共有的函数
	}
	print(mi.begin(), mi.end());	
	cout << mi.count(8) << endl;
	mi.erase(5);//关联式容器共有
	print(mi.begin(), mi.end());	
	mi.insert(mi.begin(), 9);
	print(mi.begin(), mi.end());	
	mi.insert(4);
	print(mi.begin(), mi.end());	
	multiset<int>::iterator b, e;
	b = mi.lower_bound(8);	
	e = mi.upper_bound(8);
	while(b!=e){ cout << *b++ << ' '; }
	cout << endl;
	//返回8的区间
	typedef multiset<int>::iterator MII;
	pair<MII, MII> p=mi.equal_range(8);
	print(p.first, p.second);
}

