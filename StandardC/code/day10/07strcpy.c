#include <stdio.h>
#include <string.h>
int main() {
    char firstStr[30];
    char secondStr[30];
    printf("请输入第一个字符串：");
    fgets(firstStr, 30, stdin);
    //strcpy函数可以完成字符串
    //拷贝，第一个参数是目标
    //数组的地址，第二个参数
    //是原始字符串的地址。如果
    //目标数组的空间不够有可能
    //会出问题。
    strcpy(secondStr, firstStr);
    printf("字符串是%s\n", secondStr);
    return 0;
}
