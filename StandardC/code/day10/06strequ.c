#include <stdio.h>

int strequ(char *pFirstStr, char *pSecondStr) {
    char *pFStr = pFirstStr;
    char *pSStr = pSecondStr;
    int pos = 0;
    while ((pFStr[pos] == pSStr[pos]) && ('\0' != pFStr[pos])) {
        pos++;
    }
    if (pFStr[pos] != pSStr[pos]) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    char firstStr[30];
    char secondStr[30];
    int result = 0;
    printf("������һ���ַ�����");
    fgets(firstStr, 30, stdin);
    printf("���ٴ�����һ���ַ�����");
    fgets(secondStr, 30, stdin);
    result = strequ(firstStr, secondStr);
    if ( 0 == result) {
        printf("�ַ��������\n");
    }
    else {
        printf("�ַ������\n");
    }
    return 0;
}
