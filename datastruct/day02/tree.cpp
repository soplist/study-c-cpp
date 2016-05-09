#include <iostream>
using namespace std;
typedef int T;
struct Node{
	T data;
	Node* left;
	Node* right;
	Node(const T& d)
		:data(d),left(),right(){}
/*
	~Node(){
		cout<<"~Node("<<data<<")"<<endl;
	}
*/
};
class Tree{
	Node* root;//指向根结点的指针
	int sz;//结点个数
	typedef Node* tree;//树类型
	//将结点pn插入到树t中
	void insert(Node* pn, tree& t){
		if(t==NULL){ t = pn; return; }
		if(pn->data>t->data){
			insert(pn, t->right);
		}else{ insert(pn, t->left); }
	}
	//打开一棵树t
	void travel(tree& t){
		if(t==NULL) return;
		travel(t->left);
		cout << t->data << ' ';
		travel(t->right);
	}
	//释放一棵树
	void clear(tree& t){
		if(t==NULL) return;	
		clear(t->left);
		clear(t->right);
		delete t;	
		t = NULL;
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
};
int main()
{
	Tree t;
	t.insert(5);t.insert(3);t.insert(1);
	t.insert(4);t.insert(7);t.insert(6);
	t.travel();	
	cout << t.size() << endl;
	t.clear();
	cout << t.size() << endl;
	t.travel();
}

