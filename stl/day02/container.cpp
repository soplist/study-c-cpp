//��׼�����Ĺ���
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;//�пղι���
	int a[8] = {1,2,3,4,6,8,8,5};
	vector<int> vi(a, a+8);//���乹��
	cout << v.size() << endl;
	cout << vi.size() << endl;	
	//vi�е�ֵ����һ��,������
	vector<int>::iterator it=vi.begin();
	vector<int>::iterator eit=vi.end();
	while(it!=eit){
		cout << *it << ' ';		
		it++;
	}
	cout << endl;
	//���������
	vector<int>::reverse_iterator rb,re;
	rb = vi.rbegin();
	re = vi.rend();
	while(rb!=re){
		cout << *rb << ' ';
		rb++;
	}			
	cout << endl;
	//ֻ��������
	vector<int>::const_iterator cit;
	cit = vi.begin();
	//*cit = 100;	
}

