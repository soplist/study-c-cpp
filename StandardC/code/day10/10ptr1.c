#include <stdio.h>
int main() {
    int values[3] = {0};
    printf("&values[0]��%d\n", &values[0]);
    printf("values��%d\n", values);
    printf("&values[1]��%d\n", &values[1]);
    printf("values + 1��%d\n", values + 1);
    printf("&values[2]��%d\n", &values[2]);
    printf("values + 2��%d\n", values + 2);
    return 0;
}
