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
public:
	List():head(0),sz(0){}	
	~List(){clear();};
	//�������в���һ��Ԫ��(β��)
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
	//��ָ��λ�ò���Ԫ��
	bool insert(int pos, const T& d){
		if(pos<0||pos>sz) return false;
		Node* pn = new Node(d);
		//�����ͷ��
		if(pos==0){
			pn->next = head;
			head = pn;
			sz++;
			return true;
		}
		//�������ͷ��
		Node* p = head;
		for(int i=0; i<pos-1; i++){
			p = p->next;
		}	
		pn->next = p->next;
		p->next = pn;
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
		Node* p = head;
		//ɾ��0λ�õ�Ԫ��
		if(pos==0){
			head = head->next;
			delete p;
			sz--;
			return true;
		}
		//ɾ����0λ�õ�Ԫ��
		for(int i=0; i<pos-1; i++){
			p = p->next;
		}			
		Node* q = p->next;
		p->next = q->next;
		delete q;	
		sz--;
		return true;
	}
	//����ָ��λ�õ�Ԫ��
	T& at(int pos)throw(out_of_range){
		if(pos<0||pos>=sz)
			throw out_of_range("out");
		Node* p = head;
		for(int i=0; i<pos; i++){
			p = p->next;
		}
		return p->data;
	}
	//���������е�Ԫ�ظ���
	int size(){ return sz;}	
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
	
}

