#include "list.h"

List::Node*& List::getptr(int pos){
	if(pos==0) return head;
	Node* p = head;
	for(int i=0; i<pos-1; i++){
		p = p->next;	
	}
	return p->next;
}
//向链表中插入一个元素(尾插)
bool List::insert(const T& d){
	return insert(sz, d);
}	
//在指定位置插入元素
bool List::insert(int pos, const T& d){
	if(pos<0||pos>sz) return false;
	Node* pn = new Node(d);
	Node*& r = getptr(pos);
	pn->next = r;
	r = pn;
	sz++;
	return true;
}
//打印链表
void List::travel(){
	Node* p = head;
	while(p){
		cout << p->data << ' ';
		p = p->next;
	}	
	cout << endl;
}
//清空链表
void List::clear(){
	Node* p = head;
	while(head){
		head = head->next;
		delete p;
		p = head;
	}		
	sz = 0;
}
//删除指定位置的元素
bool List::erase(int pos){
	if(pos<0||pos>=sz) return false;
	Node*& r = getptr(pos);
	Node* q = r;
	r = r->next;
	delete q;
	sz--;
	return true;
}
//返回指定位置的元素
T& List::at(int pos)throw(out_of_range){
	if(pos<0||pos>=sz)
		throw out_of_range("out");
	Node*& r = getptr(pos);
	return r->data;
}

