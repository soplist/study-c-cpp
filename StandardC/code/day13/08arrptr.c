#include <stdio.h>
int main() {
    int values[5] = {1, 2, 3, 4, 5};
    int (*pValues)[5];
    pValues = &values;
    /*int pValues[1][5] = {{1, 2, 3, 4, 5}};
    int *values = pValues[0];*/
    printf("pValues��%p\n", pValues);
    printf("values��%p\n", values);
    printf("pValues + 1��%p\n", pValues + 1);
    printf("values + 1��%p\n", values + 1);
    return 0;
}
