//标准容器的共性
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;//有空参构造
	int a[8] = {1,2,3,4,6,8,8,5};
	vector<int> vi(a, a+8);//区间构造
	cout << v.size() << endl;
	cout << vi.size() << endl;	
	//vi中的值遍历一遍,迭代器
	vector<int>::iterator it=vi.begin();
	vector<int>::iterator eit=vi.end();
	while(it!=eit){
		cout << *it << ' ';		
		it++;
	}
	cout << endl;
	//反向迭代器
	vector<int>::reverse_iterator rb,re;
	rb = vi.rbegin();
	re = vi.rend();
	while(rb!=re){
		cout << *rb << ' ';
		rb++;
	}			
	cout << endl;
	//只读迭代器
	vector<int>::const_iterator cit;
	cit = vi.begin();
	//*cit = 100;	
}

