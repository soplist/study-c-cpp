#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;
namespace emis{
class Employee{
/*Ա����*/
public:
		Employee(void);
		Employee(int nId);

		friend istream& operator>> (istream& is, Employee& emp);
		friend ostream& operator<< (ostream& os, Employee& emp);
		
private:
		int m_id;//Ա��id
		string m_strName;//����
		bool m_bGender;//�Ա�
		int m_age;//����
};
}
#endif //_EMPLOYEE_H

