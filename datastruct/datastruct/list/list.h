#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <stdexcept>
using namespace std;
typedef int T;
//�����
class List{
	struct Node{//�ڲ���
		T data;
		Node* next;
		Node(const T& d):data(d),next(){}
	};
	Node* head;//ͷָ��
	int sz;//Ԫ�ظ���
	Node*& getptr(int pos);
public:
	List():head(0),sz(0){}	
	~List(){clear();};
	//������в���һ��Ԫ��(β��)
	bool insert(const T& d);
	//��ָ��λ�ò���Ԫ��
	bool insert(int pos, const T& d);
	//��ӡ���
	void travel();
	//�������
	void clear();
	//ɾ��ָ��λ�õ�Ԫ��
	bool erase(int pos);
	//����ָ��λ�õ�Ԫ��
	T& at(int pos)throw(out_of_range);
	//��������е�Ԫ�ظ���
	int size(){ return sz;}	
	//��������һ��Ԫ��
	T& back(){ return at(sz-1);}
	//���ص�һ��Ԫ��
	T& front(){ return at(0);}
	//�ж��Ƿ�Ϊ��
	bool empty(){return sz==0;}
	//ɾ������һ��Ԫ��
	void pop_back(){ erase(sz-1);}
	//ɾ����һ��Ԫ��
	void pop_front(){ erase(0);}
	//���β������һ��Ԫ��
	void push_back(const T& d){
		insert(sz, d);
	}	
	//���ͷ������һ��Ԫ��
	void push_front(const T& d){
		insert(0, d);
	}
};
#endif


