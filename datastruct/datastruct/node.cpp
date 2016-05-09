#include <iostream>
using namespace std;
typedef char T;
//节点类型
struct Node{
	T data;//数据
	Node* next;//下一个节点的位置
	Node(const T& d):data(d),next(){}
};
void print(Node* p){
	while(p){
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
int main()
{
	Node n1('A'), n2('B'),
			n3('C'),n4('D');
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	Node* head = &n1;
	print(head);	
	//删除节点n2
	//n1.next = &n3;
	//n1.next = n1.next->next;
	n1.next = n2.next;
	print(head);
	//插入节点n2到n3的后面
	n3.next = &n2;
	n2.next = &n4;
	print(head);
	//指针的引用
	Node*& pr = n3.next;	
	//n3.next = n3.next->next;
	pr = pr->next;
	print(head);	
}

