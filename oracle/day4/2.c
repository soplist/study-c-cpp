#include<stdio.h>
int main() {
    int seconds = 0;
    printf("������һ������:");
    scanf("%d",&seconds);
    printf("ת�����:%02d:%02d:%02d\n",seconds/3600,(seconds%3600)/60,seconds%60);
    return 0;
}
