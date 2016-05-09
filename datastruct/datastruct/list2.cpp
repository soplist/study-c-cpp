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
	Node*& getptr(int pos){
		if(pos==0) return head;
		Node* p = head;
		for(int i=0; i<pos-1; i++){
			p = p->next;	
		}
		return p->next;
	}
public:
	List():head(0),sz(0){}	
	~List(){clear();};
	//向链表中插入一个元素(尾插)
	bool insert(const T& d){
		return insert(sz, d);
	}	
	//在指定位置插入元素
	bool insert(int pos, const T& d){
		if(pos<0||pos>sz) return false;
		Node* pn = new Node(d);
		Node*& r = getptr(pos);
		pn->next = r;
		r = pn;
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
		Node*& r = getptr(pos);
		Node* q = r;
		r = r->next;
		delete q;
		sz--;
		return true;
	}
	//返回指定位置的元素
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		Node*& r = getptr(pos);
		return r->data;
	}
	//返回链表中的元素个数
	int size(){ return sz;}	
	//返回最后一个元素
	T& back(){ return at(sz-1);}
	//返回第一个元素
	T& front(){ return at(0);}
	//判断是否为空
	bool empty(){return sz==0;}
	//删除最后一个元素
	void pop_back(){ erase(sz-1);}
	//删除第一个元素
	void pop_front(){ erase(0);}
	//链表尾部插入一个元素
	void push_back(const T& d){
		insert(sz, d);
	}	
	//链表头部插入一个元素
	void push_front(const T& d){
		insert(0, d);
	}
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
	list.back() = 999;
	list.front() = 888;
	list.travel();
	list.pop_back();
	list.travel();
	list.pop_front();
	list.travel();
	list.push_back(777);
	list.push_front(666);
	list.travel();
	cout << list.size() << endl;
	list.clear();
	cout << list.size() << endl;
	list.travel();
}

