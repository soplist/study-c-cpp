#include <stdio.h>
#define LOCAL(x)   l_##x
int readInt();
int main() {
    int LOCAL(Values)[3] = {0};
    LOCAL(Values)[0] = readInt();
    LOCAL(Values)[1] = readInt();
    LOCAL(Values)[2] = readInt();
    printf("LOCAL(Values)[0]ÊÇ%d\n", l_Values[0]);
    printf("LOCAL(Values)[1]ÊÇ%d\n", l_Values[1]);
    printf("LOCAL(Values)[2]ÊÇ%d\n", l_Values[2]);
    return 0;
}
