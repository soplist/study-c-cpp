#include <stdio.h>
#define PI   3.14
#define CIRCLE(r)    2*PI*(r)
int readInt();
int main() {
    int radius = 0;
    printf("������԰�İ뾶��");
    radius = readInt();
    printf("Բ�İ뾶��%f\n", CIRCLE(radius + 1));
    return 0;
}
