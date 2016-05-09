#include <stdio.h>
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("usage: 11fileread file\n");
        return 0;
    }
    FILE * pFile = fopen(argv[1], "r");
    if (NULL != pFile) {
        char aChar;
        aChar = fgetc(pFile);
        while (EOF != aChar) {
            printf("%c", aChar);
            aChar = fgetc(pFile);
        }
        printf("\n");
        fclose(pFile);
        pFile = NULL;
    }
    return 0;
}
