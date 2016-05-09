#include <iostream>
using namespace std;
//定义类Person
class Person{
public:
	string name;
	bool gender;
	int age;
//private:
	void show(){
		cout << name << "," << 
		(gender?"男":"女") << "," << age 
		<< endl;
	}
};
int main()
{
	Person p;
	p.name = "Daniel";
	p.gender = true;
	p.age = 30;
	p.show();
}

