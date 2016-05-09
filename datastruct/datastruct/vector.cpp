#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
typedef int T;
class Vector{
	T* data;//ָ�򱣴�����Ԫ�ص��ڴ�����
	int sz;//Ԫ�ظ���
	int max;//��¼�ڴ�����Ŀռ��С
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
	//��ָ��λ�ò���Ԫ��	
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
	//ɾ��ָ��λ�õ�Ԫ��
	bool erase(int pos){
		if(pos<0||pos>=sz) return false;
		for(int i=pos; i<sz-1; i++){
			data[i] = data[i+1];
		}	
		sz--;
		return true;	
	}
	//�±�����[]
	T& operator[](int pos){
		return data[pos];
	}	
	//����ָ���±�λ�õ�Ԫ��
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		return data[pos];
	}	
	//����Ԫ�ظ���
	int size(){ return sz; }
	//�������һ��Ԫ��
	T& back(){return data[sz-1];}
	//���ص�һ��Ԫ��
	T& front(){ return data[0];}
	//ɾ�����һ��Ԫ��
	void pop_back(){ sz--; }
	//��ָ��Ԫ�ز��뵽���
	void push_back(const T& d){
		insert(sz, d);
	}
	//�������Ԫ��
	void clear(){ sz=0; }	
	//�ж��Ƿ�Ϊ��(û��Ԫ��)
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
	Vector v;
	for(int i=0; i<15; i++){
		v.insert(0, i);
	}
	v.insert(15, 100);
	v.insert(-1, 200);
	v.insert(20, 300);	
	cout << v << endl;
	v.erase(15);
	cout << v << endl;
	v.erase(0);
	cout << v << endl;
	v.erase(3);
	cout << v << endl;
	v.erase(18);
	cout << v << endl;
	v[0] = 12345;
	v.at(1) = 67890;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}	
	cout << endl;
	v.pop_back();
	v.pop_back();
	cout << v << endl;
	v.push_back(798);
	cout << v << endl;
	v.front() = 333;
	v.back() = 444;
	cout << v << endl;
	v.clear();
	cout << v << endl;
	cout << v.empty() << endl;
				
	
		
	
}

