#include <stdio.h>
int main() {
    int value = 0;
#ifndef VALUE
#define VALUE
    value += 5;
#endif

#ifndef VALUE
#define VALUE
    value += 10;
#endif
    printf("value «%d\n", value);
    return 0;
}
