#include <iostream>
using namespace std;
//参数叫哑元,为了向前兼容,++,--重载时会用
void fa(int){
	cout << "fa" << endl;
}
/*
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}
void print(int* a, int n, char c){
	for(int i=0; i<n-1; i++){
		cout << a[i] << c;
	}
	cout << a[n-1] << endl;
}
*/
void print(double* a, int n){

}
void print(int* a, int n=10, 
		char c=' ',bool f=false){//参数可以传默认值，不传参数的情况下用默认值，默认值的给法是从右向左给的，如果右边的没有，左边的不可以传，否则出错
	if(f)cout << "[";
	for(int i=0; i<n-1; i++){
		cout << a[i] << c;
	}
	cout << a[n-1] <<(f?"]":" ")<< endl;
}

//内联函数,仅仅是个请求,会不会真的内联取决于编译器
inline void fb(){

}

int main()
{
	fa(10);
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	print(a, 10);
	print(a, 10, ',');
	print(a, 10, ',', true);
	print(a);
}
/*函数的参数支持哑元
哑元是一种没有参数名的参数，主要是为了函数间的区别以及向前兼容
函数的参数可以指定默认值，当调用时没有传参，就以默认值进行函数调用。
有默认值的形参必须靠右，声明和定义分开时，默认值必需在声明中指定，定义中不再指定。
*/

