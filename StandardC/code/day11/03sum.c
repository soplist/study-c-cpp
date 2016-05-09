#include <stdio.h>
int readInt();
int main() {
    int values[3];
    values[0] = readInt();
    values[1] = readInt();
    values[2] = readInt();
    printf("values[2]是%d\n", values[2]);
    printf("values[1]是%d\n", values[1]);
    printf("values[0]是%d\n", values[0]);
    printf("求和结果是%d\n", values[0] + values[1] + values[2]);
    return 0;
}
