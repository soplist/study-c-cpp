#include <stdio.h>
int main() {
    unsigned short values[3];
    printf("sizeof(values)是%d\n", sizeof(values));
    printf("sizeof(unsigned short)是%d\n", sizeof(unsigned short));
    printf("数组中变量个数是%d\n", sizeof(values) / sizeof(unsigned short));
    return 0;
}
