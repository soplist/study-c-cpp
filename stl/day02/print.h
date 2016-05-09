#ifndef PRINT_H
#define PRINT_H
#include <iostream>
using namespace std;
template <typename T>
void print(T b, T e){
	while(b!=e){cout << *b++ << ' ';}
	cout << endl;
}
#endif

