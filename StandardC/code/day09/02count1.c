#include <stdio.h>
//声明全局变量value用于
//记录以前数到几了
unsigned short value = 0;

void count() {
    //static unsigned short value = 0;
    value++;
    printf("%hu\n", value);
}

int main() {
    unsigned short loop = 0;
    for (loop = 0; loop < 10; loop++) {
        count();
    }
    return 0;
}
