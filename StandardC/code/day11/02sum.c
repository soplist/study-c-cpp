#include <stdio.h>
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
int main() {
    int values[3];
    values[0] = readInt();
    values[1] = readInt();
    values[2] = readInt();
    printf("values[2]��%d\n", values[2]);
    printf("values[1]��%d\n", values[1]);
    printf("values[0]��%d\n", values[0]);
    printf("��ͽ����%d\n", values[0] + values[1] + values[2]);
    return 0;
}
