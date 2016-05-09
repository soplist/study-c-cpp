#include <iostream>
#include <set>
using namespace std;
#include "../day02/print.h"

int main()
{
	//投票,每得一票将其名字放入容器中
	multiset<string> ms;
	cout << "请输入得票的人名:" 
		<< "(输入Exit时结束)" << endl;
	string str;
	while(1){
		cin>>str;
		if(str=="Exit")break;
		ms.insert(str);
	}	
	print(ms.begin(), ms.end());
	//统计每个人的得票数,并打印
	multiset<string>::iterator it;
	it = ms.begin();		
	while(it!=ms.end()){
		cout<<*it<<','<<
			ms.count(*it)<<endl;
		it = ms.upper_bound(*it);
	}
}

