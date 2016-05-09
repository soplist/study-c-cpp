#include <iostream>
#include <map>
using namespace std;
#include "Hero"
void print(map<Hero, string>& hs){
	map<Hero, string>::iterator it;
	it = hs.begin();	
	while(it!=hs.end()){
		cout << (it->first).toString() 
			<< ':' << it->second << endl;
		it++;
	}	
}
int main()
{
	Hero h1("ΤС��", 8000);
	Hero h2("ΤһЦ", 2000);
	Hero h3("����", 3000);
	Hero h4("˵����", 1000);
	//key����֧��"<"�������
	map<Hero, string> hs;	
	hs.insert(make_pair(h1,"��Сͨ��"));
	hs.insert(make_pair(h2,"��������"));
	hs.insert(make_pair(h3,"������ʹ"));
	hs.insert(make_pair(h4,"��������"));
	print(hs);
	cout << "---------------" << endl;
	Hero h5("��ң", 3000);	
	//hs.insert(make_pair(h5,"������ʹ"));
	hs[h5] = "������ʹ";
	print(hs);
}

