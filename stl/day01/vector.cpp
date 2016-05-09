#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
//类的模板
template <typename T> class Vector{
	T* data;//指向保存数据元素的内存区域
	int sz;//元素个数
	int max;//记录内存区域的空间大小
	void expand(){
		max *= 2;
		T* t = new T[max];
		for(int i=0; i<sz; i++){
			t[i] = data[i];
		}
		delete[] data;
		data = t;
	}
public:
	explicit Vector(int n=10)
		:max(n),sz(){
		data = new T[max];
	}
	Vector(const Vector&v){
		sz = v.sz;
		max = v.max;
		data = new T[max];
		for(int i=0; i<sz; i++){
			data[i] = v.data[i];
		}
	}
	~Vector(){delete[] data;}
	Vector& operator=(const Vector&v){
		if(this==&v) return *this;
		delete[] data;
		data = new T[v.max];	
		sz = v.sz;
		max = v.max;
		for(int i=0; i<sz; i++){
			data[i] = v.data[i];
		}	
		return *this;
	}	
	//向指定位置插入元素	
	bool insert(int pos, const T& d){
		if(pos<0||pos>sz) return false;
		if(sz==max)expand();
		for(int i=sz; i>pos; i--){
			data[i] = data[i-1];
		}	
		data[pos] = d;
		sz++;
		return true;
	}
	//删除指定位置的元素
	bool erase(int pos){
		if(pos<0||pos>=sz) return false;
		for(int i=pos; i<sz-1; i++){
			data[i] = data[i+1];
		}	
		sz--;
		return true;	
	}
	//下标运算[]
	T& operator[](int pos){
		return data[pos];
	}	
	//返回指定下标位置的元素
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		return data[pos];
	}	
	//返回元素个数
	int size(){ return sz; }
	//返回最后一个元素
	T& back(){return data[sz-1];}
	//返回第一个元素
	T& front(){ return data[0];}
	//删除最后一个元素
	void pop_back(){ sz--; }
	//将指定元素插入到最后
	void push_back(const T& d){
		insert(sz, d);
	}
	//清空所有元素
	void clear(){ sz=0; }	
	//判断是否为空(没有元素)
	bool empty(){return sz==0;}

	friend ostream& operator<<(
		ostream&o, const Vector&v){
		for(int i=0; i<v.sz; i++){
			cout << v.data[i] << ' ';
		}
		return o;
	}	
};
int main()
{
	Vector<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	Vector<string> vs;
	vs.push_back("abc");
	Vector<double> vd;
	vd.push_back(3.14);
	
		
	
}

