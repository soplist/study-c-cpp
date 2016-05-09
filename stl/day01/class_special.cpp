#include <iostream>
using namespace std;
//类模板,返回指定类型的名称
template <typename T> class Type{
public:
	static string name(){
		return typeid(T).name();
	}
};
//专门针对int类型的类模板,此模板是对上面模板的一个特例,叫特化模板(类模板的特化)
template <> class Type<int>{
public:
	static string name(){return "int";}
};
template <> class Type<double>{
public:
	static string name(){
		return "double";
	}
};
template <> class Type<char>{
public:
	static string name(){return "char";}
};

//类模板的偏特化,偏特化通常针对指针
template <typename T> class Type<T*>{
public:
	static string name(){
		string str = "pointer of ";
		str += Type<T>::name();
		return str;
	}
};
class Employee{};
int main()
{
	cout<<Type<Employee>::name()<<endl;
	cout<<Type<int>::name()<<endl;//int	
	cout<<Type<double>::name()<<endl;
	cout<<Type<char>::name()<<endl;
	cout<<Type<int*>::name()<<endl;
	cout<<Type<char*>::name()<<endl;
	cout<<Type<Employee*>::name()<<endl;
	cout<<Type<char**>::name()<<endl;
	
		
}

