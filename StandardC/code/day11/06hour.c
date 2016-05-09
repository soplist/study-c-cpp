#include <stdio.h>
#define SECPERHOUR    (60 * 60)
int readInt();
int main() {
    int seconds = 0;
    seconds = readInt();
    printf("小时数是%d\n", seconds / SECPERHOUR);
    return 0;
}
