#include <stdio.h>
#define MUL(x,y)      ((x)*(y))
int main() {
    int x = 0;
    int y = 0;
    x = readInt();
    y = readInt();
    printf("��ͽ����%d\n", MUL(x,y));
    return 0;
}
