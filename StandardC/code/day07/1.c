#include <stdio.h>
int main() {
    unsigned short values[3];
    printf("请输入第一个数字：");
    scanf("%hu", &values[0]);
    printf("请输入第二个数字：");
    scanf("%hu", &values[1]);
    printf("请输入第三个数字：");
    scanf("%hu", &values[2]);
    printf("values[2]是%hu\n", values[2]);
    printf("values[1]是%hu\n", values[1]);
    printf("values[0]是%hu\n", values[0]);
    printf("求和结果是%hu\n", values[0] + values[1] + values[2]);
    return 0;
}
