#include <stdio.h>
#define SQUARE(x)  ((x)*(x))
int readInt();
int square(int x) {
    return x * x;
}
int main() {
    int x = 0;
    printf("������Ҫ��������֣�");
    x = readInt();
    printf("��������%d\n", SQUARE(++x));
    return 0;
}
