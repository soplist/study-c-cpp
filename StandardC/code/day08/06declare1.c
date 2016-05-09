#include <stdio.h>

//这一行是函数声明，它是把
//函数中的大括号省略掉以后
//得到的
int add(int , int );

int main() {
    printf("add(2, 3)是%d\n", add(2, 3));
    return 0;
}

int add(int x, int y) {
    return x + y;
}
