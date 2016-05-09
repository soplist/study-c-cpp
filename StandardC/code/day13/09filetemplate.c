#include <stdio.h>
int main() {
    FILE * pFile = fopen("a.txt", "w");
    if (NULL != pFile) {
        fclose(pFile);
        pFile = NULL;
    }
    return 0;
}
