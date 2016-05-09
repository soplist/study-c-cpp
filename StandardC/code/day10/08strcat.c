#include <stdio.h>
#include <string.h>
int main() {
    char firstStr[20] = "abc";
    char secondStr[] = "xyz";
    //strcat函数可以把secondStr
    //连接在firstStr字符串后边
    //firstStr中一定要预留足够
    //的空间
    strcat(firstStr, secondStr);
    printf("结果字符串是%s\n", firstStr);
    return 0;
}
