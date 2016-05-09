#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
void sort(int*, int);
int main()
{
	int data[LEN];
	srand(time(0));
	for(int i=0; i<LEN; i++){
		data[i] = rand()%LEN;	
	}
	print(data, 10);
	clock_t beg = clock();	
	sort(data, LEN);
	clock_t end = clock();
	print(data, 10);
	cout << "ÏûºÄÊ±¼ä:" << 
		((end - beg)*1.0/CLOCKS_PER_SEC)
		<< "s" << endl;
}

