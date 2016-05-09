#include <stdio.h>
#define PI   3.14
#define CIRCLE(r)    2*PI*(r)
int readInt();
int main() {
    int radius = 0;
    printf("请输入园的半径：");
    radius = readInt();
    printf("圆的半径是%f\n", CIRCLE(radius + 1));
    return 0;
}
