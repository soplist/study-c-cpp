#include <stdio.h>
int main() {
    int values[5] = {0};
    FILE *pFile = NULL;
    int loop = 0;
    pFile = fopen("c.txt", "rb");
    if (NULL != pFile) {
        for (loop = 0; loop <= 4; loop++) {
           fread(&values[loop], sizeof(int), 1, pFile);
           rewind(pFile);
        }
        fclose(pFile);
        pFile = NULL;
    }
    for (loop = 0; loop <= 4; loop++) {
        printf("values[%d]ÊÇ%d\n", loop, values[loop]);
    }
    return 0;
}
