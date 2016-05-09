#include <stdio.h>
#define GLOBAL(x)   g_##x 
int GLOBAL(Values)[3];
int readInt();
int main() {
    GLOBAL(Values)[0] = readInt();
    GLOBAL(Values)[1] = readInt();
    GLOBAL(Values)[2] = readInt();
    printf("GLOBAL(Values)[0]ÊÇ%d\n", GLOBAL(Values)[0]);
    printf("GLOBAL(Values)[1]ÊÇ%d\n", GLOBAL(Values)[1]);
    printf("GLOBAL(Values)[2]ÊÇ%d\n", GLOBAL(Values)[2]);
    return 0;

}
