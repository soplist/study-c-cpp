#include <iostream>
using namespace std;
//多个模板参数
template <typename K, typename V>
class Map{
	K keys[100];//所有的键
	V values[100];//所有的值
	int sz;//多少个键值对
public:
	Map():sz(){}	
	void push(K key, V value){
		keys[sz] = key;
		values[sz] = value;
		sz++;
	}
	V get(K key){
		int pos;
		for(pos=0; pos<sz;  pos++){
			if(keys[pos] == key) break;
		}	
		return values[pos];
	}
};

int main()
{
	Map<string, string> mss;
	mss.push("name", "daniel");
	mss.push("age", "30");
	string str = mss.get("name");	
	cout << str << endl;

	Map<int, string> mis;
	mis.push(1, "表哥");
	mis.push(2, "二表哥");
	str = mis.get(2);	
	cout << str << endl;
}

