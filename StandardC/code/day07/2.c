#include <stdio.h>
int main() {
    unsigned short values[3];
    int loop = 0;
    unsigned short sum = 0;
    for (loop = 0; loop <= 2; loop++ ) {
        printf("�������%d�����֣�", loop + 1);
        scanf("%hu", &values[loop]);
    }
    for (loop = 2; loop >= 0; loop--) {
        printf("values[%d]��%hu\n", loop, values[loop]);
        sum += values[loop];
    }
    printf("��ͽ����%hu\n", sum);
    return 0;
}
