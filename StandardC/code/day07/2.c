#include <stdio.h>
int main() {
    unsigned short values[3];
    int loop = 0;
    unsigned short sum = 0;
    for (loop = 0; loop <= 2; loop++ ) {
        printf("请输入第%d个数字：", loop + 1);
        scanf("%hu", &values[loop]);
    }
    for (loop = 2; loop >= 0; loop--) {
        printf("values[%d]是%hu\n", loop, values[loop]);
        sum += values[loop];
    }
    printf("求和结果是%hu\n", sum);
    return 0;
}
