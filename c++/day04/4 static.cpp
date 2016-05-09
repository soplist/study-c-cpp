#include <iostream>
using namespace std;
class Sample{
public:
	int x;
	static int s;//静态成员变量. 
};
int Sample::s;//给静态成员变量分配空间
int main()
{
	Sample s1;
	s1.x = 100;
	s1.s = 1000;
	Sample s2;
	s2.x = 200;
	s2.s = 2000;
	cout << s1.x << ',' << s1.s << endl;
	cout << s2.x << ',' << s2.s << endl;
}

