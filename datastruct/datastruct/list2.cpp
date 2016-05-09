#include <iostream>
#include <stdexcept>
using namespace std;
typedef int T;
//������
class List{
	struct Node{//�ڲ���
		T data;
		Node* next;
		Node(const T& d):data(d),next(){}
	};
	Node* head;//ͷָ��
	int sz;//Ԫ�ظ���
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
	//�������в���һ��Ԫ��(β��)
	bool insert(const T& d){
		return insert(sz, d);
	}	
	//��ָ��λ�ò���Ԫ��
	bool insert(int pos, const T& d){
		if(pos<0||pos>sz) return false;
		Node* pn = new Node(d);
		Node*& r = getptr(pos);
		pn->next = r;
		r = pn;
		sz++;
		return true;
	}
	//��ӡ����
	void travel(){
		Node* p = head;
		while(p){
			cout << p->data << ' ';
			p = p->next;
		}	
		cout << endl;
	}
	//�������
	void clear(){
		Node* p = head;
		while(head){
			head = head->next;
			delete p;
			p = head;
		}		
		sz = 0;
	}
	//ɾ��ָ��λ�õ�Ԫ��
	bool erase(int pos){
		if(pos<0||pos>=sz) return false;
		Node*& r = getptr(pos);
		Node* q = r;
		r = r->next;
		delete q;
		sz--;
		return true;
	}
	//����ָ��λ�õ�Ԫ��
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		Node*& r = getptr(pos);
		return r->data;
	}
	//���������е�Ԫ�ظ���
	int size(){ return sz;}	
	//�������һ��Ԫ��
	T& back(){ return at(sz-1);}
	//���ص�һ��Ԫ��
	T& front(){ return at(0);}
	//�ж��Ƿ�Ϊ��
	bool empty(){return sz==0;}
	//ɾ�����һ��Ԫ��
	void pop_back(){ erase(sz-1);}
	//ɾ����һ��Ԫ��
	void pop_front(){ erase(0);}
	//����β������һ��Ԫ��
	void push_back(const T& d){
		insert(sz, d);
	}	
	//����ͷ������һ��Ԫ��
	void push_front(const T& d){
		insert(0, d);
	}
};

int main()
{
	List list;//������
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
		cout << "Խ��" << endl;
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

