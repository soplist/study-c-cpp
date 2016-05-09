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
    printf("请输入一个字符串：");
    fgets(str, 10, stdin);
    len = strlen(str);
    printf("字符串长度是：%d\n", len);
    len = strlength(str);
    printf("字符串长度是：%d\n", len);
    return 0;
}
