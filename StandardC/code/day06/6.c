#include <stdio.h>
int main() {
    unsigned short leaves = 0;
    unsigned short flag = 0;
    printf("请输入叶子的片数：");
    scanf("%hu", &leaves);
    while (leaves > 0) {
        leaves--;
        if (0 == flag) {
            printf("她爱我\n");
        }
        else {
            printf("她不爱我\n");
        }
        flag = 1 - flag;
    }
    return 0;
}
