#include <stdio.h>
int main() {
    unsigned short values[3];
    printf("�������һ�����֣�");
    scanf("%hu", &values[0]);
    printf("������ڶ������֣�");
    scanf("%hu", &values[1]);
    printf("��������������֣�");
    scanf("%hu", &values[2]);
    printf("values[2]��%hu\n", values[2]);
    printf("values[1]��%hu\n", values[1]);
    printf("values[0]��%hu\n", values[0]);
    printf("��ͽ����%hu\n", values[0] + values[1] + values[2]);
    return 0;
}
