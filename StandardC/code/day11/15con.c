#include <stdio.h>
#define ZHAOBENSHAN
int readInt();
int main() {
    int dish = 0;
    printf("请点菜：");
    dish = readInt();
#ifndef ZHAOBENSHAN
    printf("这道菜有\n");
#else
    if (1 == dish) {
        printf("没有\n");
    }
    else {
        printf("这个真没有\n");
    }
#endif
    return 0;
}
