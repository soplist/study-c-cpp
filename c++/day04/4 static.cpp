#include <iostream>
using namespace std;
class Sample{
public:
	int x;
	static int s;//��̬��Ա����. 
};
int Sample::s;//����̬��Ա��������ռ�
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

