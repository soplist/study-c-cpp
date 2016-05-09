#include <iostream>
using namespace std;
typedef int T;
//������ʵ�ּ򵥵�ջ
class Stack{
	T data[10];
	int sz;
public:
	Stack():sz(){}
	//��ջ
	void push(const T& d)
		throw(const char*){
		if(sz==10)throw "full";
		data[sz++] = d;
	}		
	//��ջ
	void pop()throw(const char*){
		if(sz==0)throw "empty";
		sz--;
	}
	//�鿴ջ��Ԫ��
	T top()const throw(const char*){ 
		if(sz==0)throw "empty";
		return data[sz-1];
	}	
	//����ջ��С
	int size()const{ return sz;}
	//ջ�Ƿ�Ϊ��
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
	//����Ԫ�س�ջ����ӡ��ջ˳��
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}		
	cout << endl;
	cout << s.size() << endl;
}

