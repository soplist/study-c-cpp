#include <stdio.h>
int main() {
    int * pValues[3];
    int firstValue[3] = {3, 4, 5};
    int secondValue[4] = {6, 7, 8, 9};
    int thirdValue[5] = {10, 11, 12, 13, 14};
    pValues[0] = firstValue;
    pValues[1] = secondValue;
    pValues[2] = thirdValue;
    printf("pValues[1][3]ÊÇ%d\n", pValues[1][3]);
    return 0;
}
