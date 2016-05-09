#include <stdio.h>
#define MAX(x,y)   ((x)>(y)?(x):(y))
int readInt();
int main() {
    int x = 0;
    int y = 0;
    x = readInt();
    y = readInt();
    printf("最大的那个是%d\n", MAX(x,y));
    return 0;
}
