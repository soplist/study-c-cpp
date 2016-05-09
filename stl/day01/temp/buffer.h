#ifndef BUFFER_H
#define BUFFER_H
//类模板
template <typename T> class Buffer{
	T buf[100];//T是泛型类型
	int sz;
public:
	Buffer():sz(){}
	void push(T x);
	T get();
};
#endif


