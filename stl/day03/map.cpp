#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, string> m;
	pair<string, string> p1;
	p1.first = "name";
	p1.second = "Daniel";
	m.insert(p1);
	pair<string, string> 
		p2("age", "30");
	m.insert(p2);
	m.insert(map<string,string>
		::value_type("gender", "male"));	
	m.insert(make_pair("address","BJ"));
	//key不重复,直接插入元素
	m["salary"] = "123456";
	//key重复,插入直接失败,数据丢掉	
	m.insert(make_pair("age", "31"));
	//key重复,修改指定key对应的value值
	m["age"] = "31";
	map<string,string>::iterator it;
	it = m.begin();
	while(it!=m.end()){
		cout<<it->first<<'='
			<<it->second<<endl; 
		it++;
	}	
	cout << "---------------" << endl;
	//通过已知的key,获取对应的value
	cout << m["name"] << endl;
	cout << m["salary"] << endl;
	cout << m["abc"] << endl;	
}

