#include <stdio.h>
int main() {
    unsigned short values[3];
    printf("sizeof(values)��%d\n", sizeof(values));
    printf("sizeof(unsigned short)��%d\n", sizeof(unsigned short));
    printf("�����б���������%d\n", sizeof(values) / sizeof(unsigned short));
    return 0;
}
