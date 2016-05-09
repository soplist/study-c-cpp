#include <stdio.h>
#define PRINT(x)  printf(#x"=%d\n", (x))
int readInt();
int main() {
    int value = 0;
    value = readInt();
    PRINT(value);
    printf("value=%d\n", value);
}
