#include <stdio.h>
int readInt() {
    int ret = 0;
    int value = 0;
    printf("������һ�����֣�");
    ret = scanf("%d", &value);
    while (0 == ret) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("���ٴ��������֣�");
        ret = scanf("%d", &value);
    }
    scanf("%*[^\n]");
    scanf("%*c");
    return value;
}
int main() {
    int value = 0;
    value = readInt();
    printf("�����������%d\n", value);
    return 0;
}
