#include <iostream>
#include <set>
using namespace std;
#include "../day02/print.h"

int main()
{
	//ͶƱ,ÿ��һƱ�������ַ���������
	multiset<string> ms;
	cout << "�������Ʊ������:" 
		<< "(����Exitʱ����)" << endl;
	string str;
	while(1){
		cin>>str;
		if(str=="Exit")break;
		ms.insert(str);
	}	
	print(ms.begin(), ms.end());
	//ͳ��ÿ���˵ĵ�Ʊ��,����ӡ
	multiset<string>::iterator it;
	it = ms.begin();		
	while(it!=ms.end()){
		cout<<*it<<','<<
			ms.count(*it)<<endl;
		it = ms.upper_bound(*it);
	}
}

