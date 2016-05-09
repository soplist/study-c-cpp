#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> powers;//ÿ��ս����
	map<string, int> skills;//����ս����
	//ÿ���������Ĺ���
	multimap<string,string> mss;  
	skills.insert(
		make_pair("������",1000));
	skills["Ұ��ȭ"] = 2000;
	skills["��������"] = 1200;
	skills["��Ů�ľ�"] = 800;	 		
	skills["ͯ�ӹ�"] = 900;
	//mss["����"] = "��������";//ERROR
	mss.insert(
		make_pair("����","��������"));	
	mss.insert(
		make_pair("����","������"));	
	mss.insert(
		make_pair("����","ͯ�ӹ�"));	
	mss.insert(
		make_pair("��������","ͯ�ӹ�"));	
	//����ս����,���뵽powers��
	typedef multimap<string,string> MSS;
	MSS::iterator it = mss.begin();
	while(it!=mss.end()){
		string name = it->first; //����
		int power = 0; //power
		MSS::iterator next 
			= mss.upper_bound(it->first);
		while(it!=next){
			power += skills[it->second];
			it++;
		}
		powers[name] = power;	
	}	
	
	map<string,int>::iterator it2;
	it2 = powers.begin();
	while(it2!=powers.end()){
		cout << it2->first << ','
			<< it2->second << endl;
		it2++;
	}

}

