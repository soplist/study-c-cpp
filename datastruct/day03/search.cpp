#include <iostream>
using namespace std;
//返回c在cs中的下标,不存在返回-1
int search(char* cs, int n, char c){
	int L = 0;//左
	int R = n-1;//右
	while(L<=R){
		int M = (L+R)/2;
		if(cs[M] == c) return M;//找着了
		else if(c > cs[M]){ L = M+1; }
		else{ R = M-1; }
	}
	return -1;//没找着
}
//能用递归实现吗
int search2(
	char* cs, int from, int to, char c){
	if(from > to) return -1;
	int m = (from + to) / 2;
	if(cs[m] == c) return m;
	if(c > cs[m] ) 
		return search2(cs, m+1, to, c);
	return search2(cs, from, m-1, c);
}
int search2(char* cs, int n, char c){
	return search2(cs, 0, n-1, c);		
}

int main()
{
	char cs[] = 
		{'A', 'B', 'C', 'D', 'E', 'F'};
	//找E的下标是多少
	int pos = search2(cs, 6, 'E');
	if(pos==-1)cout<<"not found"<<endl;
	else cout<<"E pos :"<<pos<<endl;
	cout<<search2(cs, 6, 'A')<<endl;
	cout<<search2(cs, 6, 'F')<<endl;
	cout<<search2(cs, 6, 'G')<<endl;
}

