#include <stdio.h>
int main() {
    unsigned short value1 = 0;
    unsigned short value2 = 0;
    int ret = 0;
    printf("�������һ�����֣�");
    ret = scanf("%hu", &value1);
    do {
        scanf("%*[^\n]");
        scanf("%*c");
        if (0 == ret) {
            printf("���ٴ������һ�����֣�");
            ret = scanf("%hu", &value1);
        }
    } while(0 == ret);
    printf("������ڶ������֣�");
    ret = scanf("%hu", &value2);
    do {
        scanf("%*[^\n]");
        scanf("%*c");
        if (0 == ret) {
            printf("���ٴ�����ڶ������֣�");
            ret = scanf("%hu", &value2);
        }
    } while (0 == ret);
    printf("��ͽ����%hu\n", value1 + value2);
    return 0;
}
