#include <stdio.h>
int main() {
    unsigned short loop = 0;
    short value = 0;
    short sum = 0;
    for (loop = 0; loop < 3; loop++) {
        printf("���������֣�");
        scanf("%hd", &value);
        sum += value;
    }
    printf("��ͽ����%hd\n", sum);
}
