#include <stdio.h>
#include "readInt.h"
int readInt() {
    int value = 0;
    int ret = 0;
    printf("������һ��������");
    ret = scanf("%d", &value);
    while (0 == ret) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("���ٴ�����һ��������");
        ret = scanf("%d", &value);
    }
    scanf("%*[^\n]");
    scanf("%*c");
    return value;
}
