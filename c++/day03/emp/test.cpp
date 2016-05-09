#include "employee.h"
#include "date.h"
int main()
{
	Employee e("Daniel",1980,2,25,123456);
	e.show();
	Date d(1984,8,8);
	Employee e2("Guodh", d, 150000);
	e2.show();
}

