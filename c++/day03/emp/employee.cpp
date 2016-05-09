#include "employee.h"
#include <iostream>
void Employee::show(){
	cout << "我叫" << name << 
		",我出生于:" << birth.toString()
		<<",我月薪:" << salary << endl;
}

