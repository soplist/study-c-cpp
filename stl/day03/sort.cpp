#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
#include "../day02/print.h"

int main()
{
	int a[10] = {1,4,3,2,5,6,7,8,0,9};
	sort(a, a+10);
	print(a, a+10);
	vector<char> vc;
	vc.push_back(69);
	vc.push_back(65);
	vc.push_back(66);
	vc.push_back(68);
	//Ĭ����<���������������
	sort(vc.begin(), vc.end());
	print(vc.begin(), vc.end());
	int b[6] = {3,2,4,1,9,5};
	list<int> li(b, b+6);
	//sortֻ�ܶ������洢�����ݽ�������
	//sort(li.begin(), li.end());	
	li.sort();
	print(li.begin(), li.end());

	//�Ӵ�С����
	sort(vc.begin(), vc.end(), 
		greater<int>());
	print(vc.begin(), vc.end());	
	vector<int> vi(b, b+6);
	print(vi.begin(), vi.end());
	bool cmp(int a, int b);
	sort(vi.begin(), vi.end(), cmp);		
	print(vi.begin(), vi.end());
}
bool cmp(int a,int b){return a%3<b%3;}

