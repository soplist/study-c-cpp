#include <stdio.h>
int main() {
    char str[10];
    printf("请输入一个字符串：");
    gets(str);  //这个函数禁止使用
    printf("字符串是%s\n", str);
    return 0;
}
