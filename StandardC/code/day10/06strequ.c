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
    printf("请输入一个字符串：");
    fgets(firstStr, 30, stdin);
    printf("请再次输入一个字符串：");
    fgets(secondStr, 30, stdin);
    result = strequ(firstStr, secondStr);
    if ( 0 == result) {
        printf("字符串不相等\n");
    }
    else {
        printf("字符串相等\n");
    }
    return 0;
}
