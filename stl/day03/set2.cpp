#include <iostream>
#include <set>
using namespace std;
#include "Hero"

int main()
{
	Hero h1("������", 5000);
	Hero h2("���޼�", 4000);
	set<Hero> hs;
	hs.insert(h1);//h1����֧��"<"�����
	hs.insert(h2);
	Hero h3("���", 4000);
	hs.insert(h3);		
	cout << hs.size() << endl;
	set<Hero>::iterator it = hs.begin();
	while(it!=hs.end()){
		//ͨ��������ֻ�ܵ���ֻ������
		cout << it->toString() << endl;
		it++;
	}
}

