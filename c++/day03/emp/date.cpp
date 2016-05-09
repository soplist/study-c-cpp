#include "date.h"
#include <cstdio>
string Date::toString(){
	char buf[20];
	sprintf(buf,"%4d-%02d-%02d",
		year, month, day);
	return buf;
}

