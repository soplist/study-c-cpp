#include <stdio.h>
//定义add函数用于演示参数变量
//的数值和地址
int add(int x, int y) {
    printf("add函数中变量x的地址是%p\n", &x);
    printf("add函数中变量x的数值是%d\n", x);
    return x + y;
}

int main() {
    //声明变量x，然后数组这个
    //变量的地址和数据，用于
    //和add函数中的x变量作比较
    //以证明他们是两个完全不同的
    //变量
    int x = 4;
    printf("main函数中x变量的地址是%p\n", &x);
    printf("main函数中x变量的数值是%d\n", x);
    int y = 5;
    add(x, y);
    return 0;
}
