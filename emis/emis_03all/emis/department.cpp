namespace emis{  
/*≤ø√≈¿‡*/
	DepartMent(void){}
	DepartMent(int nId){}
/*
*
*TODO
*
**/
	bool deleteEmp(int empId){}
	void listEmp(vector<Empoyee>& Emps);
	bool modifyEmp(Employee& emp);	
	
	friend istream& operator>>(istream& is, DepartMent& dept);
	friend ostream& operator<<(ostream& os,const DepartMent& dept);
}

