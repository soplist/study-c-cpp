#include <stdio.h>
#define MAX(x,y)   ((x)>(y)?(x):(y))
int readInt();
int main() {
    int x = 0;
    int y = 0;
    x = readInt();
    y = readInt();
    printf("�����Ǹ���%d\n", MAX(x,y));
    return 0;
}
