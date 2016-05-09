#include <stdio.h>
int main() {
    int value = 0;
    int *pValue = NULL;
    pValue = &value;
    value = 7;
    printf("%d\n", pValue[0]);
    return 0;
}
