#include <stdio.h>
int main() {
    FILE * pFile = NULL;
    pFile = fopen("c.txt", "rb");
    if (NULL != pFile) {
        int value;
        fseek(pFile, 4, SEEK_SET);
        fread(&value, sizeof(int), 1, pFile);
        printf("value «%d\n", value);
        fseek(pFile, 4, SEEK_CUR);
        fread(&value, sizeof(int), 1, pFile);
        printf("value «%d\n", value);
        fseek(pFile, -12, SEEK_END);
        fread(&value, sizeof(int), 1, pFile);
        printf("value «%d\n", value);
        fclose(pFile);
        pFile = NULL;
    }
    return 0;
}
