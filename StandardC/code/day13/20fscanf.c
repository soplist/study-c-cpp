#include <stdio.h>
int main() {
    int value = 0;
    char aChar = 0;
    float aFloat = 0;
    FILE *pFile = NULL;
    pFile = fopen("e.txt", "r");
    if (NULL != pFile) {
       fscanf(pFile, "%d %c %f", &value, &aChar, &aFloat);
       fclose(pFile);
       pFile = NULL;
       printf("value «%d\n", value);
       printf("aChar «%c\n", aChar);
       printf("aFloat «%f\n", aFloat);
    }
    return 0;
}
