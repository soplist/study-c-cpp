#include <stdio.h>

typedef struct {
    char values[2];
    unsigned short value;
} SD;

typedef union {
    char values[2];
    unsigned short value;
} UD ;

int main() {
    printf("sizeof(UD)��%d\n", sizeof(UD));
    printf("sizeof(SD)��%d\n", sizeof(SD));
    return 0;
}
