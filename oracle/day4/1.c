#include<stdio.h>
int main() {
    int num = 0;
    int q,i = 0;
    printf("������һ����λ����:");
    scanf("%d",&num);
    printf("���:");
    for(i = 0; i < 4; i++) {
         q = num % 10;
         num = num / 10;
         printf("%d",q);
    }
    printf("\n");
    return 0;
}
