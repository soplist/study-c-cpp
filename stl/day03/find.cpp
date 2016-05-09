#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "../day02/print.h"
using namespace std;
bool isEven(int x){return x%2==0;}
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	vector<int> vi(a, a+10);
	vector<int>::iterator it = 
		find(vi.begin(), vi.end(), 8);
	if(it!=vi.end()){
		cout << "found " << *it << endl;
	}	
	it = find_if(vi.begin(), vi.end(), 
		isEven);
	if(it!=vi.end()){
		cout << "even: " << *it << endl;
	}
	int cnt = count_if(vi.begin(), 
		vi.end(), isEven);
	cout << "evens:" << cnt << endl;

	int cards[10]={0,1,2,3,4,5,6,7,8,9};
	//ÂÒÐò
	srand(time(0));
	random_shuffle(cards,cards+10);
	print(cards, cards+10);	
}

