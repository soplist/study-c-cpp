#include <stdio.h>
#include <string.h>
int strlength(char *pStr) {
    char *pString = pStr;
    int pos = 0;
    while ('\0' != pString[pos]) {
       pos++;
    }
    return pos;
}
int main() {
    char str[10];
    int len = 0;
    printf("������һ���ַ�����");
    fgets(str, 10, stdin);
    len = strlen(str);
    printf("�ַ��������ǣ�%d\n", len);
    len = strlength(str);
    printf("�ַ��������ǣ�%d\n", len);
    return 0;
}
