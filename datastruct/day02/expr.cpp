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
//如果oper1高于oper2返回true,否则false
bool prior(char oper1, char oper2){
	return (oper1=='*'||oper1=='/') 
		&& (oper2=='+'||oper2=='-');	
}
int main()
{
	string str = "1+2*3-(5+1)/2";
	Stack res;//结果栈
	Stack oper;//运算符栈
	for(int i=0; i<str.size(); i++){
		char ch = str[i];
		if(isdigit(ch)){//数字
			res.push(ch);
		}else if(ch=='('){//左括号
			oper.push(ch);
		}else if(ch==')'){//右括号
			while(oper.top()!='('){
				res.push(oper.top());
				oper.pop();
			}
			oper.pop();
		}else{//运算符
			while(!oper.empty() 
				&& oper.top()!='(' 
				&& !prior(ch,oper.top())){
				res.push(oper.top());
				oper.pop();
			}
			oper.push(ch);
		}
	}
	//运算符==>结果
	while(!oper.empty()){
		res.push(oper.top());
		oper.pop();
	}
	while(!res.empty()){
		oper.push(res.top());
		res.pop();
	}
	//打印	
	while(!oper.empty()){
		cout << oper.top() << ' ';
		oper.pop();
	}	
	cout << endl;
}

