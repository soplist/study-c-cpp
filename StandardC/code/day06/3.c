#include <stdio.h>
int main() {
    unsigned short price = 0;
    unsigned short guess = 0;
    printf("������۸����ݣ�");
    scanf("%hu", &price);
    while (price != guess) {
        printf("��²�۸�");
        scanf("%hu", &guess);
        if (guess > price) {
            printf("������Ǯ\n");
        }
        else if (guess == price) {
            printf("��Ű�\n");
        }
        else {
            printf("̫������\n");
        }
    }
    return 0;
}
