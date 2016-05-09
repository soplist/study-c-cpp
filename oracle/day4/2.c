#include<stdio.h>
int main() {
    int seconds = 0;
    printf("请输入一个秒数:");
    scanf("%d",&seconds);
    printf("转换完成:%02d:%02d:%02d\n",seconds/3600,(seconds%3600)/60,seconds%60);
    return 0;
}
