#include <iostream>
#include <cctype>
using namespace std;
typedef char T;
const int LEN = 50;
class Stack{
	T data[LEN];
	int sz;
public:
	Stack():sz(){}
	void push(const T& d)
		throw(const char*){
		if(sz==LEN)throw "full";
		data[sz++] = d;
	}		
	void pop()throw(const char*){
		if(sz==0)throw "empty";
		sz--;
	}
	T top()const throw(const char*){ 
		if(sz==0)throw "empty";
		return data[sz-1];
	}	
	int size()const{ return sz;}
	bool empty()const{ return sz==0;}	
};
//���oper1����oper2����true,����false
bool prior(char oper1, char oper2){
	return (oper1=='*'||oper1=='/') 
		&& (oper2=='+'||oper2=='-');	
}
int main()
{
	string str = "1+2*3-(5+1)/2";
	Stack res;//���ջ
	Stack oper;//�����ջ
	for(int i=0; i<str.size(); i++){
		char ch = str[i];
		if(isdigit(ch)){//����
			res.push(ch);
		}else if(ch=='('){//������
			oper.push(ch);
		}else if(ch==')'){//������
			while(oper.top()!='('){
				res.push(oper.top());
				oper.pop();
			}
			oper.pop();
		}else{//�����
			while(!oper.empty() 
				&& oper.top()!='(' 
				&& !prior(ch,oper.top())){
				res.push(oper.top());
				oper.pop();
			}
			oper.push(ch);
		}
	}
	//�����==>���
	while(!oper.empty()){
		res.push(oper.top());
		oper.pop();
	}
	while(!res.empty()){
		oper.push(res.top());
		res.pop();
	}
	//��ӡ	
	while(!oper.empty()){
		cout << oper.top() << ' ';
		oper.pop();
	}	
	cout << endl;
}

