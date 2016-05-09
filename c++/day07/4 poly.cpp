#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//������,�Ƚϸ߼������ͣ�������������࣬��ʾ���л��ŵĶ���
class CRE{
public:
	//���麯��
	virtual string getName() = 0;
	virtual int getPH() = 0;
	virtual int getACT() = 0;
	virtual void setPH(int ph) = 0;
};
//������
class Human : public CRE{
	string name;
	int PH;
	int ACT;
public:
	Human(string n, int ph, int act)
	:name(n),PH(ph),ACT(act){}
	string getName(){return name;}
	int getPH(){return PH;}
	void setPH(int ph){PH=ph;}
	int getACT(){return ACT;}
	//���麯��
	virtual void move() = 0;	
	virtual void attack(CRE& cre) = 0;//CRE& cre������Թ�����������
};
//����
class ORC : public CRE{
	string name;
	int PH;
	int ACT;
public:
	ORC(string n, int ph, int act)
		:name(n),PH(ph),ACT(act){}
	string getName(){return name;}
	int getPH(){return PH;}
	void setPH(int ph){PH=ph;}
	int getACT(){return ACT;}
	virtual void move() = 0;	
	virtual void attack(CRE& cre) = 0;
};
//ʵ����,����ʵ�����еĴ��麯��
class MK : public Human{
public:
	MK(string n, int ph, int act)
	:Human(n, ph, act){}
	virtual void move(){
		cout << getName()<< "�ƶ�" << endl;
	}	
	virtual void attack(CRE& cre){
		int act = getACT()/10;
		cre.setPH(cre.getPH()-act);
		cout << getName() << "���" << cre.getName() << act << "��Ѫ"<<endl;	
	}
};
class AM : public Human{
public:
	AM(string n, int ph, int act)
	:Human(n, ph, act){}
	virtual void move(){
		cout << getName()<< "����" << endl;
	}	
	virtual void attack(CRE& cre){
		int act = getACT()/10;
		cre.setPH(cre.getPH()-act);
		cout << getName() << "���" << cre.getName() << act << "��Ѫ"<<endl;	
	}
};
	
class BM : public ORC{
public:
	BM(string n, int ph, int act)
	:ORC(n, ph, act){}
	virtual void move(){
		cout << getName()<<"���粽"<<endl;
	}	
	virtual void attack(CRE& cre){
		int act = getACT()/10;
		cre.setPH(cre.getPH()-act);
		cout << getName() << "���" << cre.getName() << act << "��Ѫ"<<endl;	
	}
};

void fight(Human*ph[],int n1,
		ORC*po[],int n2)
{
	srand(time(0));//���������
	for(int i=0; i<10; i++){
		for(int j=0; j<5; j++){
			int index = rand()%5;	
			ph[j]->attack(*po[index]);//ph�ĵ�j�����󣬵���attack���������±�Ϊindex��po ����
		}			
		for(int j=0; j<5; j++){
			int index = rand()%5;//rand()��5ȡ��õ�һ���±꣬������index����
			po[j]->attack(*ph[index]);
		}
		int cur = time(NULL);
		while(time(NULL)==cur);
	}	
}

int main()
{
	Human* hs[5] = {
		new MK ("ɽ��1", 120, 100),
		new MK ("ɽ��2", 120, 100),
		new MK ("ɽ��3", 120, 100),
		new AM ("��ʦ1", 200, 80),
		new AM("��ʦ2", 200, 80)
	};
	ORC* os[5] = {
		new BM("��ʥ1", 150, 100),	
		new BM("��ʥ2", 150, 100),	
		new BM("��ʥ3", 150, 100),	
		new BM("��ʥ4", 150, 100),	
		new BM("��ʥ5", 150, 100)	
	};	
	fight(hs, 5, os, 5);	
}

