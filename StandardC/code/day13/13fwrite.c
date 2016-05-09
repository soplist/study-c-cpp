#include <stdio.h>
int main() {
    int values[5] = {5, 6, 7, 8, 9};
    FILE *pFile = NULL;
    pFile = fopen("c.txt", "w");
    if (NULL != pFile) {
        fwrite(values, sizeof(int), 5, pFile);
        fclose(pFile);
        pFile = NULL;
    }
    return 0;
}
