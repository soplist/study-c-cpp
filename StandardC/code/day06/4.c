#include <stdio.h>
int main() {
    unsigned short loop = 0;
    short sum = 0;
    loop = 13;
    while (loop <= 23) {
        if (0 == (loop % 2)) {
            sum -= loop;
        }
        else {
            sum += loop;
        }
        loop++;
    }
    printf("��ͽ����%hd\n", sum);
    return 0;
}
