// 头文件date.h Date类的声明
#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;
class Date{
	int year;
	int month;
	int day;
public:
	Date(int y=1900, int m=1, int d=1)
	:year(y),month(m),day(d){}
	string toString();
};
#endif

