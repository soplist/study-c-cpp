#include <stdio.h>
int main() {
    unsigned short leaves = 0;
    unsigned short flag = 0;
    printf("������Ҷ�ӵ�Ƭ����");
    scanf("%hu", &leaves);
    while (leaves > 0) {
        leaves--;
        if (0 == flag) {
            printf("������\n");
        }
        else {
            printf("��������\n");
        }
        flag = 1 - flag;
    }
    return 0;
}
