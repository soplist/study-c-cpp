#include <iostream>
using namespace std;
typedef int T;
//用数组实现简单的栈
class Stack{
	T data[10];
	int sz;
public:
	Stack():sz(){}
	//入栈
	void push(const T& d)
		throw(const char*){
		if(sz==10)throw "full";
		data[sz++] = d;
	}		
	//出栈
	void pop()throw(const char*){
		if(sz==0)throw "empty";
		sz--;
	}
	//查看栈顶元素
	T top()const throw(const char*){ 
		if(sz==0)throw "empty";
		return data[sz-1];
	}	
	//返回栈大小
	int size()const{ return sz;}
	//栈是否为空
	bool empty()const{ return sz==0;}	
};
int main()
{
	Stack s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	/*
	for(int i=0; i<10; i++){
		s.push(i);
	}
	*/
	cout << s.size() << endl;
	//所以元素出栈并打印出栈顺序
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}		
	cout << endl;
	cout << s.size() << endl;
}

