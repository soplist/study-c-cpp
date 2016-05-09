#include <iostream>
using namespace std;
//数组类
typedef int T;
class Array{
	T* data;//指向堆中的数据
	int sz;//表示数据的个数
	int max;//堆中的空间大小
	//扩容
	void expand(){
		max = 2*max;	
		T* t = new T[max];//申请一片新空间，放在临时变量里面
		for(int i=0; i<sz; i++){
			t[i] = data[i];//把把原来数据放入t中
		}
		delete[] data;//释放掉原来的空间
		data = t;//date指针指向新的空间
	}
public:
	//构造函数不允许隐式调用
	explicit Array(int n=5):max(n),sz(0){
		data = new T[n];
	}
	~Array(){ delete[] data;}	
	Array(const Array&a){
		max = a.max;
		sz = a.sz;
		data = new T[max];
		for(int i=0; i<sz; i++){
			data[i] = a.data[i];
		}	
	}
	Array& operator=(const Array&a){
		if(this==&a) return *this;
		delete[] data;
		data = new T[a.max];//申请新的空间和a里面的空间一样大	
		max = a.max;//拷贝a里面的数据
		sz = a.sz;
		for(int i=0; i<sz; i++){
			data[i] = a.data[i];
		}
		return *this;
	}	

	bool insert(int index, const T& d){//在下标为index这个位置插入数据
		if(index<0||index>sz)return false;
		if(sz==max)expand();//扩容
		for(int i=sz; i>index; i--){//下标向后移动一位
			data[i] = data[i-1];
		}
		data[index] = d;//在下标为index这个位置插入数据
		sz++;
		return true;
	}
	bool push_back(const T& d){//放在最后一个位置
		return insert(sz, d);
	}
	friend ostream& operator<<
		(ostream&o, const Array& a){
		for(int i=0; i<a.sz; i++){
			o << a.data[i] << ' ';
		}
		return o;
	}
	T& operator[](int index){
		return data[index];//返回本身
	}
	T& at(int index){
		if(index<0 || index>=sz)throw"out";//下标越界，抛异常
		return data[index];
	}
	T& operator[](char c){//用字符作下标
		return data[c-'a'];
	}
	T& operator[](double d){
		return data[(int)(d+0.5)];
	}
	int size(){return sz;}
};
int main()
{
	Array a;//a是个对象，当作数组来用，
	a.insert(0,1);
	a.insert(1,2);
	a.push_back(3);
	cout << a << endl;
	Array b = a;
	Array c;
	c = a;
	a[0] = 100;//a.operator[](0) = 100;
	a[1] = 200;//a.operator[](1) = 200;
	for(int i=0; i<a.size(); i++){
		cout << a[i] << ' ';
	}			
	cout << endl;
	a['a'] = 123;//a.operator[]('a')=123;
	a['b'] = 456;
	a['c'] = 789;
	cout << a <<endl;
	a[2.13] = 213;
	a[0.8] = 8;
	a[0.2] = 2;
	cout << a << endl;
	//==========================
	//Array arr = 100;//Array arr(100);
	
}
/*Array这个类的主要作用是提供一个数组的类，这个类的某一个对象就是数组，可以用这个类直接构造数组

*/

