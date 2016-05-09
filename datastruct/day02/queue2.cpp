#include <iostream>
using namespace std;
//循环队列
typedef int T;
const int LEN = 8;//队列长度
class Queue{
	T data[LEN];
	int f;//队列头
	int sz;//队列中的元素个数
public:
	Queue():sz(), f(){}
	void push(const T& d)
		throw(const char*){
		if(sz==LEN)throw "full";
		data[(f+sz)%LEN] = d;
		sz++;
	}
	void pop()throw(const char*){
		if(sz==0)throw "empty";
		f++;
		f %= LEN;
		sz--;
	}
	T& front()throw(const char*){ 
		if(sz==0)throw "empty";
		return data[f];
	}
	T& back()throw(const char*){
		if(sz==0)throw "empty";
		return data[(f+sz-1)%LEN];
	}
	int size(){ return sz;}
	bool empty(){ return sz==0;}
};
int main()
{
	Queue q;
	for(int i=1; i<=8; i++){
		q.push(i);
	}
	q.pop();
	q.pop();
	q.push(9);
	q.push(10);
	q.pop();
	q.push(11);
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}			
	cout << endl;
}

