#include <stdio.h>
int main() {
    char str[7777777] = "abcdef";
    char *pStr = str;
    printf("%s\n", "abcdef");
    printf("%s\n", str);
    printf("%s\n", pStr);
    return 0;
}
