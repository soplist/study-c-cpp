#include <iostream>
#include <set>
using namespace std;
#include "Hero"

int main()
{
	Hero h1("张三丰", 5000);
	Hero h2("张无忌", 4000);
	set<Hero> hs;
	hs.insert(h1);//h1必需支持"<"运算符
	hs.insert(h2);
	Hero h3("杨过", 4000);
	hs.insert(h3);		
	cout << hs.size() << endl;
	set<Hero>::iterator it = hs.begin();
	while(it!=hs.end()){
		//通过迭代器只能调用只读函数
		cout << it->toString() << endl;
		it++;
	}
}

