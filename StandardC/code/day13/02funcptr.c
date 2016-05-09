#include <stdio.h>
int add(int x, int y) {
    return x + y;
}

int mul(int x, int y) {
    return x * y;
}

int main() {
    //声明一个函数指针变量
    //声明语法类似函数声明
    int (*pFunc)(int, int);
    pFunc = add;
    printf("add是%p\n", add);
    printf("pFunc是%p\n", pFunc);
    printf("pFunc(3, 4)是%d\n", pFunc(3, 4));
    pFunc = mul;
    printf("pFunc(3, 4)是%d\n", pFunc(3, 4));
    return 0;
}
