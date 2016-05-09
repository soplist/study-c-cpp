#include <iostream>
#include <list>
#include "print.h"
using namespace std;
class Emp{
	int id;
	string name;
	int age;
	double salary;
public:
	Emp(int id, string name, int age, 
		double salary):id(id),name(name),
		age(age),salary(salary){}
	friend ostream& operator<<(
		ostream&o, const Emp&e){
		return o<<e.id<<','<<e.name<<','
			<<e.age<<','<<e.salary;
	}		
	friend bool operator==(
		const Emp&e1, const Emp&e2){
		return e1.id==e2.id;
	}
	friend bool operator<(
		const Emp&e1, const Emp&e2){
		return e1.salary < e2.salary;
	}
	friend bool operator>(
		const Emp&e1, const Emp&e2){
		return e1.age > e2.age;
	}
};

int main()
{
	list<Emp> es;
	Emp e1(1, "Daniel", 30, 12345);
	es.push_back(e1);
	Emp e2(2, "Guodh", 31, 123456);
	es.push_back(e2);
	Emp e3(3, "Lisa", 20, 5000);
	es.push_back(e3);
	print(es.begin(), es.end());	
	//需要对象e1支持"=="号运算符
	es.remove(e1);
	print(es.begin(), es.end());	
	//需要对象支持"<"号运算符
	es.sort(less<Emp>());
	print(es.begin(), es.end());	
	//需要对象支持">"号运算符
	es.sort(greater<Emp>());	
	print(es.begin(), es.end());	
}

