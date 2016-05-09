#include <stdio.h>
int readInt() {
    int ret = 0;
    int value = 0;
    printf("请输入一个数字：");
    ret = scanf("%d", &value);
    while (0 == ret) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("请再次输入数字：");
        ret = scanf("%d", &value);
    }
    scanf("%*[^\n]");
    scanf("%*c");
    return value;
}
int main() {
    int value = 0;
    value = readInt();
    printf("输入的数字是%d\n", value);
    return 0;
}
