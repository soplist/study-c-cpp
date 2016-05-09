#include <iostream>
using namespace std;
//������
typedef int T;
class Array{
	T* data;//ָ����е�����
	int sz;//��ʾ���ݵĸ���
	int max;//���еĿռ��С
	//����
	void expand(){
		max = 2*max;	
		T* t = new T[max];//����һƬ�¿ռ䣬������ʱ��������
		for(int i=0; i<sz; i++){
			t[i] = data[i];//�Ѱ�ԭ�����ݷ���t��
		}
		delete[] data;//�ͷŵ�ԭ���Ŀռ�
		data = t;//dateָ��ָ���µĿռ�
	}
public:
	//���캯����������ʽ����
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
		data = new T[a.max];//�����µĿռ��a����Ŀռ�һ����	
		max = a.max;//����a���������
		sz = a.sz;
		for(int i=0; i<sz; i++){
			data[i] = a.data[i];
		}
		return *this;
	}	

	bool insert(int index, const T& d){//���±�Ϊindex���λ�ò�������
		if(index<0||index>sz)return false;
		if(sz==max)expand();//����
		for(int i=sz; i>index; i--){//�±�����ƶ�һλ
			data[i] = data[i-1];
		}
		data[index] = d;//���±�Ϊindex���λ�ò�������
		sz++;
		return true;
	}
	bool push_back(const T& d){//�������һ��λ��
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
		return data[index];//���ر���
	}
	T& at(int index){
		if(index<0 || index>=sz)throw"out";//�±�Խ�磬���쳣
		return data[index];
	}
	T& operator[](char c){//���ַ����±�
		return data[c-'a'];
	}
	T& operator[](double d){
		return data[(int)(d+0.5)];
	}
	int size(){return sz;}
};
int main()
{
	Array a;//a�Ǹ����󣬵����������ã�
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
/*Array��������Ҫ�������ṩһ��������࣬������ĳһ������������飬�����������ֱ�ӹ�������

*/

