#include <stdio.h>
int main() {
    printf("行号：%d\n", __LINE__);
    printf("文件：%s\n", __FILE__);
    printf("日期：%s\n", __DATE__);
    printf("时间：%s\n", __TIME__);
    printf("%sC标准\n", __STDC__?"符合":"不符合");
    return 0;
}
