namespace emis{
class Employee{
/*Ա����*/
Employee(void);
Employee(int nId);

friend istream& operator>> (istream& is, Employee& emp);
friend ostream& operator<< (ostream& os, Employee& emp);
}

