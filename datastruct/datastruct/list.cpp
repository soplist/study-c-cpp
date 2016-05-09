#include <iostream>
#include <stdexcept>
using namespace std;
typedef int T;
//链表类
class List{
	struct Node{//内部类
		T data;
		Node* next;
		Node(const T& d):data(d),next(){}
	};
	Node* head;//头指针
	int sz;//元素个数
public:
	List():head(0),sz(0){}	
	~List(){clear();};
	//向链表中插入一个元素(尾插)
	void insert(const T& d){
		Node* pn = new Node(d);
		if(head==NULL){
			head = pn; sz++; return;
		}
		Node* p = head;
		while(p->next){ p = p->next; }
		p->next = pn;
		sz++;
	}	
	//在指定位置插入元素
	bool insert(int pos, const T& d){
		if(pos<0||pos>sz) return false;
		Node* pn = new Node(d);
		//如果是头插
		if(pos==0){
			pn->next = head;
			head = pn;
			sz++;
			return true;
		}
		//如果不是头插
		Node* p = head;
		for(int i=0; i<pos-1; i++){
			p = p->next;
		}	
		pn->next = p->next;
		p->next = pn;
		sz++;
		return true;
	}
	//打印链表
	void travel(){
		Node* p = head;
		while(p){
			cout << p->data << ' ';
			p = p->next;
		}	
		cout << endl;
	}
	//清空链表
	void clear(){
		Node* p = head;
		while(head){
			head = head->next;
			delete p;
			p = head;
		}		
		sz = 0;
	}
	//删除指定位置的元素
	bool erase(int pos){
		if(pos<0||pos>=sz) return false;
		Node* p = head;
		//删除0位置的元素
		if(pos==0){
			head = head->next;
			delete p;
			sz--;
			return true;
		}
		//删除非0位置的元素
		for(int i=0; i<pos-1; i++){
			p = p->next;
		}			
		Node* q = p->next;
		p->next = q->next;
		delete q;	
		sz--;
		return true;
	}
	//返回指定位置的元素
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		Node* p = head;
		for(int i=0; i<pos; i++){
			p = p->next;
		}
		return p->data;
	}
	//返回链表中的元素个数
	int size(){ return sz;}	
};

int main()
{
	List list;//空链表
	list.insert(100);
	list.insert(200);
	list.insert(300);	
	list.travel();
	list.travel();
	list.clear();
	list.travel();
	list.insert(100);
	list.insert(200);
	list.insert(300);
	list.insert(400);
	list.insert(2, 500);
	list.travel();
	cout << "--------------" << endl;
	list.insert(5, 600);
	list.travel();
	list.insert(0, 700);	
	list.travel();
	list.erase(6);
	list.travel();
	list.erase(2);
	list.travel();
	list.erase(0);
	list.travel();
	list.erase(8);
	list.travel();
	list.at(0) = 111;
	list.at(3) = 222;
	list.at(2) = 333;
	try{
		list.at(4) = 444;
	}catch(out_of_range&e){
		cout << "越界" << endl;
	}
	list.travel();
	cout << list.size() << endl;	
	
}

