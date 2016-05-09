#include <stdio.h>
#include <stdlib.h>

int findchar(const char *pStr, char c) {
    const char *pString = pStr;
    int loop = 0;
    while ((c != pString[loop]) && ('\0' != pString[loop])) {
        loop++;
    }
    return loop;
}

int firststr(const char*pStr, char c, char** ppStr) {
    int pos = 0;
    const char* pString = pStr;
    pos = findchar(pString, c);
    if (0 != pos) {
        ppStr[0] = (char*)malloc(pos + 1);
        if (NULL != ppStr[0]) {
            int loop = 0;
            for (loop = 0; loop < pos; loop++) {
                ppStr[0][loop] = pStr[loop];
            }
            ppStr[0][pos] = '\0';
        }
    }
    return pos;
}

int split(const char *pStr, char c, char*** pppStr) {
    const char *pString = pStr;
    int num = 0;
    int capacity = 0;
    int pos = 0;
    int start = 0;
    capacity = 2;
    pppStr[0] = (char**)malloc(capacity * sizeof(char*));
    pppStr[0][capacity - 2] = NULL;
    pppStr[0][capacity - 1] = NULL;
    while ('\0' != pString[start]) {
        pos = firststr(&pString[start], c, &pppStr[0][num]);
        if (0 != pos) {
            num++;
            if (num == capacity) {
                capacity += 2;
                char** ppStr = NULL;
                ppStr = (char**)realloc(pppStr[0], capacity * sizeof(char*));
                if (NULL != ppStr) {
                    pppStr[0] = ppStr;
                    pppStr[0][capacity - 2] = NULL;
                    pppStr[0][capacity - 1] = NULL;
                }
                else {
                    break;
                }
            }
        }
        start += pos;
        if ('\0' != pString[start]) {
            start++;
        }
    }
    return capacity;
}

int main() {
    char str[] = "abcdef:xyza:asdf";
    char **ppStr = NULL;
    int capacity = 0;
    int loop = 0;
    //char *pStr = NULL;
    //int pos = firststr(str, ':', &pStr);
    //printf("pos是%d\n", pos);
    //printf("pStr是%s\n", pStr);
    //free(pStr);
    capacity = split(str, ':', &ppStr);
    for (loop = 0; loop <= (capacity - 1); loop++) {
        if (NULL != ppStr[loop]) {
            printf("%s\n", ppStr[loop]);
        }
        else {
            break;
        }
    }
    for (loop = 0; loop <= (capacity - 1); loop++) {
        if (NULL != ppStr[loop]) {
            free(ppStr[loop]);
        }
    }
    free(ppStr);
    ppStr = NULL;
    return 0;
}
