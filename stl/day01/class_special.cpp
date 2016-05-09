#include <iostream>
using namespace std;
//��ģ��,����ָ�����͵�����
template <typename T> class Type{
public:
	static string name(){
		return typeid(T).name();
	}
};
//ר�����int���͵���ģ��,��ģ���Ƕ�����ģ���һ������,���ػ�ģ��(��ģ����ػ�)
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

//��ģ���ƫ�ػ�,ƫ�ػ�ͨ�����ָ��
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

