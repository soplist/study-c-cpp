#include <stdio.h>
int main() {
    unsigned short values[3] = {0};
    printf("&values[0]��%p\n", &values[0]);
    printf("&values[1]��%p\n", &values[1]);
    printf("&values[2]��%p\n", &values[2]);
    printf("&values[0] + 1��%p\n", &values[0] + 1);
    printf("&values[0] + 2��%p\n", &values[0] + 2);
    printf("values��%p\n", values);
    printf("values + 1��%p\n", values + 1);
    printf("values + 2��%p\n", values + 2);
    return 0;
}
