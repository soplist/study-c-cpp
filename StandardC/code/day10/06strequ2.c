#include <stdio.h>
#include <string.h>
int main() {
    char firstStr[30];
    char secondStr[30];
    int result = 0;
    printf("请输入第一个字符串：");
    fgets(firstStr, 30, stdin);
    printf("请输入第二个字符串：");
    fgets(secondStr, 30, stdin);
    //strncmp函数用于比较两个
    //字符串中前几个字符的大小。
    //返回值是一个
    //整数，如果为0则表示相等
    //如果大于0则表示前一个
    //字符串大，如果小于0则表示
    //后一个字符串大
    result = strncmp(firstStr, secondStr, 5);
    if (0 == result) {
        printf("字符串相等\n");
    }
    else if (result > 0) {
        printf("前一个字符串大\n");
    }
    else {
        printf("后一个字符串大\n");
    }
    return 0;
}
