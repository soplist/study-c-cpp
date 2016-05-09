#include <stdio.h>
int main() {
    char str[30] = {0};
    int value = 5;
    char aChar = 'a';
    float aFloat = 2.4;
    sprintf(str, "%d %c %f", value, aChar, aFloat);
    printf("%s\n", str);

    sscanf(str, "%d %c %f", &value, &aChar, &aFloat);
    printf("value «%d\n", value);
    printf("aChar «%c\n", aChar);
    printf("aFloat «%f\n", aFloat);
    return 0;
}
