#include <stdio.h>
#define SQUARE(x)  ((x)*(x))
int readInt();
int square(int x) {
    return x * x;
}
int main() {
    int x = 0;
    printf("请输入要计算的数字：");
    x = readInt();
    printf("计算结果是%d\n", SQUARE(++x));
    return 0;
}
