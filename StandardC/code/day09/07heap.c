#include <stdio.h>
#include <stdlib.h>
int main() {
    unsigned short num = 0;
    unsigned short *pValue = NULL;
    printf("请输入数字个数：");
    scanf("%hu", &num);
    //使用下面的语句从堆中
    //分配变量
    pValue = (unsigned short*)malloc(num * sizeof(unsigned short));
    //使用下面的语句把从
    //堆中分配的变量还给
    //计算机
    free(pValue);
    return 0;
}
