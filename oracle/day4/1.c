#include<stdio.h>
int main() {
    int num = 0;
    int q,i = 0;
    printf("请输入一个四位整数:");
    scanf("%d",&num);
    printf("结果:");
    for(i = 0; i < 4; i++) {
         q = num % 10;
         num = num / 10;
         printf("%d",q);
    }
    printf("\n");
    return 0;
}
