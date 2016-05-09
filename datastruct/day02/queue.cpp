#include <iostream>
#include "../day01/list/list.h"
using namespace std;
typedef int T;
class Queue{
	List l;
public:
	void push(const T&d){
		l.push_back(d);
	}		
	void pop(){l.pop_front();}
	T& front(){return l.front();}
	T& back(){return l.back();}
	int size(){return l.size();}
	bool empty(){return l.empty();}
};
int main()
{
	Queue q;
	q.push(100);q.push(200);q.push(300);
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}

