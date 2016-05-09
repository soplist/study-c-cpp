#include <stdio.h>
int main() {
    unsigned short value1 = 0;
    unsigned short value2 = 0;
    int ret = 0;
    printf("请输入第一个数字：");
    ret = scanf("%hu", &value1);
    do {
        scanf("%*[^\n]");
        scanf("%*c");
        if (0 == ret) {
            printf("请再次输入第一个数字：");
            ret = scanf("%hu", &value1);
        }
    } while(0 == ret);
    printf("请输入第二个数字：");
    ret = scanf("%hu", &value2);
    do {
        scanf("%*[^\n]");
        scanf("%*c");
        if (0 == ret) {
            printf("请再次输入第二个数字：");
            ret = scanf("%hu", &value2);
        }
    } while (0 == ret);
    printf("求和结果是%hu\n", value1 + value2);
    return 0;
}
