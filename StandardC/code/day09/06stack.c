#include <stdio.h>
int * f1() {
    int value = 10;
    return &value;
}
void f2() {
    int num = 20;
}
int main() {
    int *pValue = f1();
    f2();
    printf("*pValue «%d\n", *pValue);
    return 0;
}
