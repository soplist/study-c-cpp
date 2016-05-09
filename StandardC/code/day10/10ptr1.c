#include <stdio.h>
int main() {
    int values[3] = {0};
    printf("&values[0]是%d\n", &values[0]);
    printf("values是%d\n", values);
    printf("&values[1]是%d\n", &values[1]);
    printf("values + 1是%d\n", values + 1);
    printf("&values[2]是%d\n", &values[2]);
    printf("values + 2是%d\n", values + 2);
    return 0;
}
