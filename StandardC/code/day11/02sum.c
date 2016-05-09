#include <stdio.h>
int readInt() {
    int value = 0;
    int ret = 0;
    printf("请输入一个整数：");
    ret = scanf("%d", &value);
    while (0 == ret) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("请再次输入一个整数：");
        ret = scanf("%d", &value);
    }
    scanf("%*[^\n]");
    scanf("%*c");
    return value;
}
int main() {
    int values[3];
    values[0] = readInt();
    values[1] = readInt();
    values[2] = readInt();
    printf("values[2]是%d\n", values[2]);
    printf("values[1]是%d\n", values[1]);
    printf("values[0]是%d\n", values[0]);
    printf("求和结果是%d\n", values[0] + values[1] + values[2]);
    return 0;
}
