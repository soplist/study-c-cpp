#include <stdio.h>
int main() {
    int loop = 0;
    //unsigned short values[3] = {1, 2};
    unsigned short values[3] = {[2] = 3, [1] = 2};
    for (loop = 0; loop <= 2; loop++) {
        printf("values[%d]ÊÇ%hu\n", loop, values[loop]);
    }
    return 0;
}
