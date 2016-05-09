#include <stdio.h>
int main(int argc, char * argv[]) {
    if (argc < 3) {
        printf("usage: 12cp <source> <dest>\n");
        return 0;
    }
    FILE *pSrcFile = NULL;
    FILE *pDestFile = NULL;
    pSrcFile = fopen(argv[1], "r");
    if (NULL != pSrcFile) {
       pDestFile = fopen(argv[2], "w");
       if (NULL != pDestFile) {
          char aChar = 0;
          aChar = fgetc(pSrcFile);
          while (EOF != aChar) {
             fputc(aChar, pDestFile);
             aChar = fgetc(pSrcFile);
          }
          fclose(pDestFile);
          pDestFile = NULL;
       }
       fclose(pSrcFile);
    }
    return 0;
}
