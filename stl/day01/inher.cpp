#include <iostream>
using namespace std;
class Parent{ string name; };
//ģ��̳���ͨ��
template <typename T> 
class Child : public Parent{};
template <typename T>
class TParent{ T data; };
//��ͨ��̳�ģ��
class Child2 : public TParent<int>{};
//ģ��̳�ģ��
template <typename T>
class TChild : public TParent<int>{};
//ģ��̳�ģ��(����ģ������Ͳ���ʹ����������Ͳ���)
template <typename T>
class TChild2 : public TParent<T>{};

int main()
{

}

