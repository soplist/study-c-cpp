#include <stdio.h>
int main() {
    unsigned short loop = 0;
    short value = 0;
    short sum = 0;
    loop = 0;
    while (loop < 3) {
        printf("请输入数字：");
        scanf("%hd", &value);
        sum += value;
        loop++;
    }
    printf("求和结果是%hd\n", sum);
}
