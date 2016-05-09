#include <stdio.h>
int main() {
    unsigned short price = 0;
    unsigned short guess = 0;
    printf("请输入价格数据：");
    scanf("%hu", &price);
    while (price != guess) {
        printf("请猜测价格：");
        scanf("%hu", &guess);
        if (guess > price) {
            printf("你真有钱\n");
        }
        else if (guess == price) {
            printf("天才啊\n");
        }
        else {
            printf("太抠门了\n");
        }
    }
    return 0;
}
