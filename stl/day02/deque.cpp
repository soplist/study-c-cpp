//dequeµÄ¸öÐÔ
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<char> dc;
	dc.push_front('A');
	dc.push_back('B');
	dc.insert(dc.end(), 'C');
	dc.push_back('D');
	dc.insert(dc.end(), 3, 'E');
	cout << dc.front() << endl;
	cout << dc.back() << endl;
	dc.pop_front();//A
	dc.pop_back();//E
	for(int i=0; i<dc.size(); i++){
		cout << dc[i] << ' ';
	}				
	cout << endl;
/*
	while(!dc.empty()){
		cout << dc.front() << ' ';
		dc.pop_front();
	}
	cout << endl;
*/
	while(!dc.empty()){
		cout << dc.back() << ' ';
		dc.pop_back();
	}
	cout << endl;
	cout << dc.size() << endl;
}

