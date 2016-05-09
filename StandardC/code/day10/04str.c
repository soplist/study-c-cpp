#include <stdio.h>
int main() {
    char str[10]; 
    printf("ÇëÊäÈëÒ»¸ö×Ö·û´®£º");
    fgets(str, 10, stdin);
    printf("×Ö·û´®ÊÇ%s\n", str);
    return 0;
}
