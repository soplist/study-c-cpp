#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//抽象类,比较高级的类型，在这代表生物类，表示所有活着的东西
class CRE{
public:
	//纯虚函数
	virtual string getName() = 0;
	virtual int getPH() = 0;
	virtual int getACT() = 0;
	virtual void setPH(int ph) = 0;
};
//抽象类
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
	//纯虚函数
	virtual void move() = 0;	
	virtual void attack(CRE& cre) = 0;//CRE& cre代表可以攻击所有生物
};
//抽象
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
//实现类,必需实现所有的纯虚函数
class MK : public Human{
public:
	MK(string n, int ph, int act)
	:Human(n, ph, act){}
	virtual void move(){
		cout << getName()<< "移动" << endl;
	}	
	virtual void attack(CRE& cre){
		int act = getACT()/10;
		cre.setPH(cre.getPH()-act);
		cout << getName() << "打掉" << cre.getName() << act << "点血"<<endl;	
	}
};
class AM : public Human{
public:
	AM(string n, int ph, int act)
	:Human(n, ph, act){}
	virtual void move(){
		cout << getName()<< "传送" << endl;
	}	
	virtual void attack(CRE& cre){
		int act = getACT()/10;
		cre.setPH(cre.getPH()-act);
		cout << getName() << "打掉" << cre.getName() << act << "点血"<<endl;	
	}
};
	
class BM : public ORC{
public:
	BM(string n, int ph, int act)
	:ORC(n, ph, act){}
	virtual void move(){
		cout << getName()<<"疾风步"<<endl;
	}	
	virtual void attack(CRE& cre){
		int act = getACT()/10;
		cre.setPH(cre.getPH()-act);
		cout << getName() << "打掉" << cre.getName() << act << "点血"<<endl;	
	}
};

void fight(Human*ph[],int n1,
		ORC*po[],int n2)
{
	srand(time(0));//产生随机数
	for(int i=0; i<10; i++){
		for(int j=0; j<5; j++){
			int index = rand()%5;	
			ph[j]->attack(*po[index]);//ph的第j个对象，调用attack函数攻击下标为index的po 对象
		}			
		for(int j=0; j<5; j++){
			int index = rand()%5;//rand()对5取余得到一个下标，保存在index里面
			po[j]->attack(*ph[index]);
		}
		int cur = time(NULL);
		while(time(NULL)==cur);
	}	
}

int main()
{
	Human* hs[5] = {
		new MK ("山丘1", 120, 100),
		new MK ("山丘2", 120, 100),
		new MK ("山丘3", 120, 100),
		new AM ("大法师1", 200, 80),
		new AM("大法师2", 200, 80)
	};
	ORC* os[5] = {
		new BM("剑圣1", 150, 100),	
		new BM("剑圣2", 150, 100),	
		new BM("剑圣3", 150, 100),	
		new BM("剑圣4", 150, 100),	
		new BM("剑圣5", 150, 100)	
	};	
	fight(hs, 5, os, 5);	
}

