#include <stdio.h>
#define UPPER(x) ((x)>='a')&&((x)<='z')?(x)-'a'+'A':(x)
int main() {
    char c;
    printf("������һ���ַ���");
    scanf("%c", &c);
    printf("��д�ַ��ǣ�%c\n", UPPER(c));
    return 0;
}
