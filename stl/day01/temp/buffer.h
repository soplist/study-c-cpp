#ifndef BUFFER_H
#define BUFFER_H
//��ģ��
template <typename T> class Buffer{
	T buf[100];//T�Ƿ�������
	int sz;
public:
	Buffer():sz(){}
	void push(T x);
	T get();
};
#endif


