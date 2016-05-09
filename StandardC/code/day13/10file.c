#include <stdio.h>
int main() {
    char str[] = "Hello World!!";
    FILE * pFile = fopen("a.txt", "w");
    if (NULL != pFile) {
        int pos = 0;
        while ('\0' != str[pos]) {
           fputc(str[pos], pFile);
           pos++;
        }
        fclose(pFile);
        pFile = NULL;
    }
    return 0;
}
