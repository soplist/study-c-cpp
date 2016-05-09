//employee.h ‘±π§¿‡:Employee
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "date.h"
using namespace std;
class Employee{
	string name;
	Date birth;	
	double salary;
public:
	Employee(string n="",int y=1900,
		int m=1,int d=1,double s=0)
		:name(n),salary(s),
		birth(y,m,d){}	
	Employee(string n,Date d,double s)
		:name(n),birth(d),salary(s){} 
	void show();
};
#endif

