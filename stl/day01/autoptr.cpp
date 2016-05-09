#include <iostream>
#include <memory>
using namespace std;
class Integer{
	int x;
public:
	Integer(int x=0):x(x){
		cout << "Integer(int)" << endl;
	}
	~Integer()
		{cout<<"~Integer()"<<endl;}
	friend ostream& operator<<(ostream&o, const Integer& i){
		return o<<i.x;
	}
};
template <typename T>
class autoptr{
	T* p;
public:
	autoptr(T* p):p(p){}
	~autoptr(){delete p;}
	T& operator*(){ return *p;}
	T* operator->(){ return p;}	
};
int main()
{
	auto_ptr<Integer> 
		pi(new Integer(100));
	cout << *pi << endl;
}

