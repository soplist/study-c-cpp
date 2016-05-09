#include <stdio.h>
unsigned short value = 1;
int main() {
    printf("value是%hu\n", value);
    unsigned short value = 2;
    printf("value是%hu\n", value);
    {
        printf("value是%hu\n", value);
        {
           unsigned short value = 3;
           printf("value是%hu\n", value);
        }
        printf("value是%hu\n", value);
    }
    return 0;
}
