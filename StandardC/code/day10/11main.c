#include <stdio.h>
int main(int argc, char* argv[]) {
    int loop = 0;
    for (loop = 0; loop <= (argc - 1); loop++) {
        printf("%s\n", argv[loop]);
    }
    return 0;
}
