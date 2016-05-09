#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <ctime>
#include "../day02/print.h"
using namespace std;

int main()
{
	//随机产生2000个20以内的整数,放入一个set中,然后打印set中的所有元素
	set<int> si;
	srand(time(0));
	for(int i=0; i<2000; i++){
		int n = rand()%20;
		si.insert(n);
	}	
	cout << si.size() << endl;
	set<int>::iterator it = si.begin();
	while(it!=si.end()){
		cout << *it++ << ' ';
	}
	cout << endl;
	cout << "---------------" << endl;
	set<string> emails;
	ifstream fin("mails.txt");
	string str;
	while(fin>>str){
		emails.insert(str);
	}
	print(emails.begin(), emails.end());
}

