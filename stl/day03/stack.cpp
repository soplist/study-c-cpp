#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main()
{
	//�ײ�Ĭ����deque
	stack<int> si;
	//�ײ���vector<int>
	stack<int, vector<int> > sv;	
	//�ײ���list<int>
	stack<int, list<int> > sl;
	sl.push(1);
	sl.push(2);
	//�ײ���set<int>,һ�㲻��������
	stack<int, set<int> > ss;
	//ss.push(3);
	//ss.push(4);

	//�ײ�Ĭ����deque	
	queue<int> qi;
	queue<int, vector<int> > qv;	
	queue<int, list<int> > ql;

	//���ȶ���
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

