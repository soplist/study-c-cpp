#include <stdio.h>
#include <stdlib.h>
int main() {
    //int values[3];
    int *values = (int*)malloc(3 * sizeof(int));
    int loop;
    values[0] = 5;
    values[1] = 6;
    values[2] = 7;
    for (loop = 0; loop <=2; loop++) {
       printf("values[%d]是%d\n",loop, values[loop]);
    }
    printf("求和结果是%d\n", values[0] + values[1] + values[2]);
    free(values);
    return 0;
}
