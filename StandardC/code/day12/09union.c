#include <stdio.h>

typedef union {
    char values[2];
    unsigned short value;
} UD ;

int main() {
    UD firstUD;
    firstUD.values[0] = 0xAB;
    firstUD.values[1] = 0xCD;
    printf("firstUD.value «%x\n", firstUD.value);
    return 0;
}
