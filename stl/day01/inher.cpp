#include <iostream>
using namespace std;
class Parent{ string name; };
//模板继承普通类
template <typename T> 
class Child : public Parent{};
template <typename T>
class TParent{ T data; };
//普通类继承模板
class Child2 : public TParent<int>{};
//模板继承模板
template <typename T>
class TChild : public TParent<int>{};
//模板继承模板(父类模板的类型参数使用子类的类型参数)
template <typename T>
class TChild2 : public TParent<T>{};

int main()
{

}

