#include <iostream>
using namespace std;
typedef char T;
//�ڵ�����
struct Node{
	T data;//����
	Node* next;//��һ���ڵ��λ��
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
	//ɾ���ڵ�n2
	//n1.next = &n3;
	//n1.next = n1.next->next;
	n1.next = n2.next;
	print(head);
	//����ڵ�n2��n3�ĺ���
	n3.next = &n2;
	n2.next = &n4;
	print(head);
	//ָ�������
	Node*& pr = n3.next;	
	//n3.next = n3.next->next;
	pr = pr->next;
	print(head);	
}

