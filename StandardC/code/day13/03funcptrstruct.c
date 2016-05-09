#include <stdio.h>
//定义结构Person用来描述
//人，其中包含了一个函数
//指针用来表示当前这个人的
//生长方式
typedef struct {
    unsigned short age;
    //用pGrow函数指针记录
    //每个人自己的生长方式
    void (*pGrow)(void * pPerson);
} Person ;

//正常人的生长方式，今年
//20明年21。参数是代表了
//某个人的结构体指针
void grow(void * pPer) {
    Person *pPerson = (Person*)pPer;
    pPerson->age++;
}

//使用了某化妆品后的生长方式，
//今年20明年18
void grow1(void * pPer) {
    Person *pPerson = (Person*)pPer;
    pPerson->age -= 2;
}

int main() {
    //声明两个结构体分别代表
    //两个不同的人，每个结构
    //体记录自己独有的生长
    //方式
    Person firstPerson = {20, grow};
    Person secondPerson = {20, grow1};
    //每个人使用自己的生长
    //方式生长一次
    firstPerson.pGrow(&firstPerson);
    secondPerson.pGrow(&secondPerson);
    //把生长后的年龄分别输出
    //到屏幕上
    printf("firstPerson.age是%hu\n", firstPerson.age);
    printf("secondPerson.age是%hu\n", secondPerson.age);
    return 0;
}





