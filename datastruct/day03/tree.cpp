#include <iostream>
using namespace std;
/* ���ڵ�����:
** 1.��������,��ֵ
** 2.find��������ָ��,������find�������䷵���߼�ֵ,true�������,false��������
**
**
*/
typedef int T;
struct Node{
	T data;
	Node* left;
	Node* right;
	Node(const T& d)
		:data(d),left(),right(){}
};
class Tree{
	Node* root;//ָ�������ָ��
	int sz;//������
	typedef Node* tree;//������
	//�����pn���뵽��t��
	void insert(Node* pn, tree& t){
		if(pn==NULL) return;//��ֹ�������
		if(t==NULL){ t = pn; return; }
		if(pn->data>t->data){
			insert(pn, t->right);
		}else{ insert(pn, t->left); }
	}
	//��ӡһ����t
	void travel(tree& t){
		if(t==NULL) return;
		travel(t->left);
		cout << t->data << ' ';
		travel(t->right);
	}
	//�ͷ�һ����
	void clear(tree& t){
		if(t==NULL) return;	
		clear(t->left);
		clear(t->right);
		delete t;	
		t = NULL;
	}
	//һ�����Ĳ���
	int high(tree& t){
		if(t==NULL) return 0;
		int lh = high(t->left);
		int rh = high(t->right);
		return (lh>rh?lh:rh)+1;		
	}	
	//�����в���ָ����Ԫ���Ƿ����,�������,����ָ��˽���ָ��,�����ڷ���NULL
	Node*& find(tree& t, const T& d){
		if(t==NULL) return t;
		if(d==t->data) return t;
		if(d>t->data)
			return find(t->right, d);
		return find(t->left, d);		
	}
public:
	Tree():root(),sz(){}
	~Tree(){clear();}
	void insert(int pos, const T& d){
		insert(d);
	}
	void insert(const T& d){
		Node* pn = new Node(d);
		insert(pn, root);	
		sz++;
	}		
	void travel(){
		travel(root);
		cout<<endl; 
	}
	void clear(){ clear(root); sz = 0; }
	int size(){ return sz; }	
	int high(){ return high(root);}
	bool find(const T& d){
		return find(root, d);
	}
	//������ɾ��ָ��Ԫ��
	bool remove(const T& d){
		Node*& r = find(root, d);	
		if(r==NULL) return false;
		//���˽������������뵽��������
		insert(r->left, r->right);	
		//��������������һ��
		Node* p = r;
		r = r->right;
		delete p;
		sz--;
		return true;
	}
	//ɾ������ֵΪd��Ԫ��
	void removeAll(const T& d){
		while(remove(d));	
	}
	//�޸�ָ��Ԫ�ص�ֵ
	bool modify(
		const T& old, const T&newval){
		//ɾ����ֵ ������ֵ
		if(remove(old)) insert(newval);
	}
};
int main()
{
	Tree t;
	t.insert(5);t.insert(3);t.insert(1);
	t.insert(4);t.insert(7);t.insert(6);
	t.travel();	
	cout << t.size() << endl;
	cout << "high=" << t.high() << endl;
	cout << t.find(5) << endl;
	cout << t.find(7) << endl;
	cout << t.find(8) << endl;
	t.remove(5);
	t.travel();
	t.modify(3, 30);
	t.travel();
	t.insert(8);
	t.insert(8);
	t.insert(8);
	t.insert(8);
	t.insert(9);
	t.travel();
	t.removeAll(8);
	t.travel();
	//�����ǲ��õĲ���
	//t.find(4)->data = 40;
	//t.travel();
}

