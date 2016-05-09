//vector的个性
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi;
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	vector<int> vi2(a, a+10);
	vector<int> vi3(5);
	cout << sizeof(vi) << endl;
	cout << sizeof(vi2) << endl;
	cout << sizeof(vi3) << endl;			
	cout << vi2.size() << endl;
	cout << vi2.capacity() << endl;
	cout << vi2.max_size() << endl;
	cout << "-----------------" << endl;
	for(int i=0; i<10; i++){
		cout << &vi[0] << ',' <<vi.size()
			<< ',' << vi.capacity()<<endl;
		vi.push_back(i);
	}

	vector<int> vi4;
	vi4.reserve(10);//约定容量
	cout << vi4.capacity() << endl;
	cout << "-----------------" << endl;
	for(int i=0; i<=10; i++){
		cout<<&vi4[0]<<','<<vi4.size()
			<<','<<vi4.capacity()<<endl;
		vi4.insert(vi4.end(),i);
	}
	cout<<&vi4[0]<<','<<vi4.size()
		<<','<<vi4.capacity()<<endl;
	//下标运算,完全可以将vector当数组来用
	vi[0] = 111;
	vi[1] = 222;
	//vi[20] = 200;
	for(int i=0; i<vi.size(); i++){
		cout << vi[i] << ' ';
	}
	cout << endl;
	vi.at(3) = 333;//vi[3] = 333;
	//vi.at(20) = 200;//越界会抛出异常
}

