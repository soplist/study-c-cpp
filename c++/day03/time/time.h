//声明类Time
#ifndef TIME_H
#define TIME_H
/*
 * 类Time的声明
 */
class Time{
	int h;
	int m;
	int s;
public:
	Time(int h=0, int m=0, int s=0);
	void dida();
	void show();
	void run();
};
#endif

