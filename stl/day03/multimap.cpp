#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> powers;//每人战斗力
	map<string, int> skills;//功夫战斗力
	//每个人修练的功夫
	multimap<string,string> mss;  
	skills.insert(
		make_pair("九阳神功",1000));
	skills["野球拳"] = 2000;
	skills["葵花宝典"] = 1200;
	skills["玉女心经"] = 800;	 		
	skills["童子功"] = 900;
	//mss["郭靖"] = "葵花宝典";//ERROR
	mss.insert(
		make_pair("郭靖","葵花宝典"));	
	mss.insert(
		make_pair("郭靖","九阳神功"));	
	mss.insert(
		make_pair("郭靖","童子功"));	
	mss.insert(
		make_pair("东方不败","童子功"));	
	//计算战斗力,插入到powers中
	typedef multimap<string,string> MSS;
	MSS::iterator it = mss.begin();
	while(it!=mss.end()){
		string name = it->first; //姓名
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

