#include <stdio.h>
#define UPPER(x) ((x)>='a')&&((x)<='z')?(x)-'a'+'A':(x)
int main() {
    char c;
    printf("请输入一个字符：");
    scanf("%c", &c);
    printf("大写字符是：%c\n", UPPER(c));
    return 0;
}
