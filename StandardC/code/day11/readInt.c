#include <stdio.h>
#include "readInt.h"
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
