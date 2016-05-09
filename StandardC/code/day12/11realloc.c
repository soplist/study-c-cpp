#include <stdio.h>
#include <stdlib.h>
int main() {
    int *pValue = NULL;
    int *pNewValue = NULL;
    pValue = (int*)malloc(3 * sizeof(int));
    printf("pValue是%p\n", pValue);
    pValue[0] = 5;
    pValue[1] = 6;
    pValue[2] = 7;
    pNewValue = (int*)realloc(pValue, 6 * sizeof(int));
    if (NULL != pNewValue) {
        pValue = pNewValue;
        printf("pValue是%p\n", pValue);
        printf("pValue[0]是%d\n", pValue[0]);
        printf("pValue[1]是%d\n", pValue[1]);
        printf("pValue[2]是%d\n", pValue[2]);
    }
    free(pValue);
    pValue = NULL;
    return 0;
}
