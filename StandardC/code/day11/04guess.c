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
            printf("�´���\n");
        }
        else if (guess < value) {
            printf("��С��\n");
        }
        else {
            printf("����\n");
        }
    } while(value != guess);
    return 0;
}
