#include <stdio.h>
int main() {
    unsigned short loop = 0;
    short value = 0;
    short sum = 0;
    for (loop = 0; loop < 3; loop++) {
        printf("请输入数字：");
        scanf("%hd", &value);
        sum += value;
    }
    printf("求和结果是%hd\n", sum);
}
