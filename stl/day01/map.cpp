#include <iostream>
using namespace std;
//���ģ�����
template <typename K, typename V>
class Map{
	K keys[100];//���еļ�
	V values[100];//���е�ֵ
	int sz;//���ٸ���ֵ��
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
	mis.push(1, "���");
	mis.push(2, "�����");
	str = mis.get(2);	
	cout << str << endl;
}

