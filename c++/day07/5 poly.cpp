#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//��ͨ����
class V{
public:
	virtual void run(){}
	virtual void stop(){}	
};
class Car : public V{
public:
	virtual void run(){
		cout << "С��������·" << endl;
	}	
	virtual void stop(){
		cout << "С�����Ⱥ��" << endl;
	}
};
class Bus : public V{
public:
	virtual void run(){
		cout << "������������·" << endl;
	}	
	virtual void stop(){
		cout << "���������Ⱥ��" << endl;
	}
};
class NO11 : public V{
public:
	virtual void run(){
		cout << "���˹���·" << endl;
	}	
	virtual void stop(){
		cout << "���˵Ⱥ��" << endl;
	}
};

void run(V* v){
	v->run();//ͨ�������͵�ָ����þ���ĺ���
}
void stop(V& v){
	v.stop();
}

int main()
{
	V* vs[5] = {//����һ�����飬�����������ÿһ��Ԫ�ض���ָ�룬���ָ��������Ǹ����͵ģ���������͵�ָ�����ָ�������ͬ�Ķ���Ψһ��Ҫ�����������ֻ����������͵Ķ��������������Ķ���
		new Bus(), new NO11(), new Car(), new Bus(), new Car()
	};
	vs[0]->run();//vs[0]������ĵ�һ��Ԫ�أ�Ҳ����һ��ָ�룬��ָ��Bus()����Ķ����ڳ��������ڼ����Bus����ĺ���
      //�����͵�ָ�����ָ�������͵Ķ���
	run(new Car());
	run(new Bus());
	run(new NO11());
   //�����͵����ÿ������õ������͵Ķ���
	Car c;
	Bus b;
	stop(c);
	stop(b);
}

