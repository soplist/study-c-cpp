//标准容器的共性
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void print(T b, T e){
	while(b!=e){cout << *b++ << ' ';}
	cout << endl;
}
int main()
{
	int a[8] = {1,2,4,8,8,6,8,5};
	print(a, a+8);
	vector<int> vi(a, a+8);
	print(vi.begin(), vi.end());
	vi.insert(vi.end(), 9);			
	print(vi.begin(), vi.end());
	vi.insert(vi.begin(), 0);
	print(vi.begin(), vi.end());
	vi.insert(++++vi.begin(), 3);
	print(vi.begin(), vi.end());
	vi.erase(vi.begin());
	print(vi.begin(), vi.end());
	vi.erase(++++++vi.begin());
	print(vi.begin(), vi.end());
	vi.erase(vi.begin(),++++vi.begin());
	print(vi.begin(), vi.end());
	vector<int> vi2 = vi;//拷贝构造
	vi.clear();
	print(vi.begin(), vi.end());
	cout << vi.size() << endl;
	//理论上的最大容量
	cout << vi.max_size() << endl;
	cout << vi.empty() << endl;
	cout << "---------------" << endl;
	vi.insert(vi.begin(), 100);
	vi.insert(vi.end(), 200);
	print(vi.begin(), vi.end());
	print(vi2.begin(), vi2.end());	
	cout << "---------------" << endl;
	vi.swap(vi2);
	print(vi.begin(), vi.end());
	print(vi2.begin(), vi2.end());	
	cout << "---------------" << endl;
	swap(vi, vi2);
	print(vi.begin(), vi.end());
	print(vi2.begin(), vi2.end());	
	cout << "---------------" << endl;
	vector<int> t = vi;
	vi = vi2;//容器会重载赋值运行符
	vi2 = t;	
	print(vi.begin(), vi.end());
	print(vi2.begin(), vi2.end());	
	cout << (vi > vi2) << endl;
}

