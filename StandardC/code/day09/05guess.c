#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    unsigned short value = 0;
    unsigned short guess = 0;
    //使用time函数获得一个时间
    //数据并把它作为种子用来
    //生成随机数
    srand(time(0));
    value = rand() % 100;
    do {
        printf("请输入猜测数据：");
        scanf("%hu", &guess);
        if (guess > value) {
           printf("猜大了\n");
        }
        else if (guess < value) {
           printf("猜小了\n");
        }
        else {
           printf("猜对了\n");
        }
    } while(guess != value);
}
