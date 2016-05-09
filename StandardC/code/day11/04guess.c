#include <stdio.h>
#include <time.h>
#include "readInt.h"
int main() {
    int value = 0;
    int guess = 0;
    srand(time(0));
    value = rand() % 100;
    do {
        guess = readInt();
        if (guess > value) {
            printf("猜大了\n");
        }
        else if (guess < value) {
            printf("猜小了\n");
        }
        else {
            printf("正好\n");
        }
    } while(value != guess);
    return 0;
}
