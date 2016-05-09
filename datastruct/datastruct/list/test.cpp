#include <iostream>
#include <stdexcept>
#include "list.h"
using namespace std;
int main()
{
	List list;//¿ÕÁ´±í
	list.insert(100);
	list.insert(200);
	list.insert(300);	
	list.travel();
	list.travel();
	list.clear();
	list.travel();
	list.insert(100);
	list.insert(200);
	list.insert(300);
	list.insert(400);
	list.insert(2, 500);
	list.travel();
	cout << "--------------" << endl;
	list.insert(5, 600);
	list.travel();
	list.insert(0, 700);	
	list.travel();
	list.erase(6);
	list.travel();
	list.erase(2);
	list.travel();
	list.erase(0);
	list.travel();
	list.erase(8);
	list.travel();
	list.at(0) = 111;
	list.at(3) = 222;
	list.at(2) = 333;
	try{
		list.at(4) = 444;
	}catch(out_of_range&e){
		cout << "Ô½½ç" << endl;
	}
	list.travel();
	cout << list.size() << endl;	
	list.back() = 999;
	list.front() = 888;
	list.travel();
	list.pop_back();
	list.travel();
	list.pop_front();
	list.travel();
	list.push_back(777);
	list.push_front(666);
	list.travel();
	cout << list.size() << endl;
	list.clear();
	cout << list.size() << endl;
	list.travel();
}

