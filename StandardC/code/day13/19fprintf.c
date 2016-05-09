#include <stdio.h>
int main() {
    int value = 5;
    char aChar = 'a';
    float aFloat = 5.6;
    FILE *pFile = NULL;
    pFile = fopen("e.txt", "w");
    if (NULL != pFile) {
        fprintf(pFile, "%d %c %f", value, aChar, aFloat);
        fclose(pFile);
        pFile = NULL;
    }
    return 0;
}
