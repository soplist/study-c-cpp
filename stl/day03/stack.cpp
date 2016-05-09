#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main()
{
	//底层默认由deque
	stack<int> si;
	//底层是vector<int>
	stack<int, vector<int> > sv;	
	//底层是list<int>
	stack<int, list<int> > sl;
	sl.push(1);
	sl.push(2);
	//底层是set<int>,一般不能这样用
	stack<int, set<int> > ss;
	//ss.push(3);
	//ss.push(4);

	//底层默认用deque	
	queue<int> qi;
	queue<int, vector<int> > qv;	
	queue<int, list<int> > ql;

	//优先队列
	priority_queue<int> pq;
	pq.push(2);
	pq.push(1);
	pq.push(4);
	pq.push(3);
	while(!pq.empty()){
		cout << pq.top() << ' ';
		pq.pop();
	}	
	cout << endl;
}

