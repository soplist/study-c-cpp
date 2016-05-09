#include <stdio.h>
int main() {
    char str[20];
    printf("请输入一个字符串：");
    //使用scanf函数从屏幕上
    //读取一个字符串到内存中
    //的数组str中，使用%s
    //占位符
    scanf("%s", str);
    printf("%s\n", str);
    return 0;
}
