#include <stdio.h>
#define ZHAOBENSHAN
int readInt();
int main() {
    int dish = 0;
    printf("���ˣ�");
    dish = readInt();
#ifndef ZHAOBENSHAN
    printf("�������\n");
#else
    if (1 == dish) {
        printf("û��\n");
    }
    else {
        printf("�����û��\n");
    }
#endif
    return 0;
}
