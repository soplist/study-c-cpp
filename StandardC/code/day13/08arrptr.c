#include <stdio.h>
int main() {
    int values[5] = {1, 2, 3, 4, 5};
    int (*pValues)[5];
    pValues = &values;
    /*int pValues[1][5] = {{1, 2, 3, 4, 5}};
    int *values = pValues[0];*/
    printf("pValues是%p\n", pValues);
    printf("values是%p\n", values);
    printf("pValues + 1是%p\n", pValues + 1);
    printf("values + 1是%p\n", values + 1);
    return 0;
}
