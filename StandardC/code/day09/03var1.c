#include <stdio.h>
unsigned short value = 1;
int main() {
    printf("value��%hu\n", value);
    unsigned short value = 2;
    printf("value��%hu\n", value);
    {
        printf("value��%hu\n", value);
        {
           unsigned short value = 3;
           printf("value��%hu\n", value);
        }
        printf("value��%hu\n", value);
    }
    return 0;
}
