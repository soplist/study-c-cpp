#include <stdio.h>
#include <stdarg.h>
int max(int cnt,...);
int main() {
    printf("%d\n", max(2, 58, 36));
    printf("%d\n", max(4, 5, 97, 26, 108));
    return 0;
}
int max(int cnt, ...) {
    va_list v;
    va_start(v, cnt);
    int maxvalue = va_arg(v, int);
    int loop = 0;
    for (loop = 1; loop < cnt; loop++) {
        int value = va_arg(v, int);
        if (value > maxvalue) {
            maxvalue = value;
        }
    }
    va_end(v);
    return maxvalue;
}
