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
	Hero h1("韦小宝", 8000);
	Hero h2("韦一笑", 2000);
	Hero h3("杨逍", 3000);
	Hero h4("说不得", 1000);
	//key必需支持"<"号运算符
	map<Hero, string> hs;	
	hs.insert(make_pair(h1,"大小通吃"));
	hs.insert(make_pair(h2,"青翼蝠王"));
	hs.insert(make_pair(h3,"光明左使"));
	hs.insert(make_pair(h4,"布袋和尚"));
	print(hs);
	cout << "---------------" << endl;
	Hero h5("范遥", 3000);	
	//hs.insert(make_pair(h5,"光明右使"));
	hs[h5] = "光明右使";
	print(hs);
}

