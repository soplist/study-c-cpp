#include <iostream>
#include "../day01/list/list.h"
using namespace std;
typedef int T;
/*
//继承方式
class Stack : private List{
public:
	void push(const T&d){push_front(d);}
	void pop(){pop_front();}
	T top(){return front();}
	int size(){return List::size();}
	bool empty(){
		return List::size()==0;
	}	
};
*/
//组合方式
class Stack{
	List l;
public:
	void push(const T& d){
		l.push_front(d);
	}	
	void pop(){l.pop_front();}
	T top(){ return l.front();}
	int size() { return l.size();}
	bool empty() { return l.empty();}	
};
int main()
{
	Stack s;
	s.push(1);
	s.push(2);s.push(3);
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}

