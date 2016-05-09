#include <iostream>
using namespace std;
//º¯ÊýÄ£°å
template <typename T> void type(T x){
	cout << typeid(x).name() << endl;
}
template <typename T,typename U>
T type_cast(U u){ return T(u);}
template <typename T, int n>
void print(T a[]){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
int main()
{
	type<int>(100);
	int x = 200;
	type<int>(x);
	string str = "abc";
	type<string>(str);		
	int r=type_cast<int, double>(3.14);
	cout << r << endl;
	int a[5] = {1,2,3,4,5};
	print<int,5>(a);
	//print<int,x>(a);
	type(x);


}

