#include <stdio.h>
typedef enum {
   SPR, 
   SUM, 
   AUT = 3, 
   WIN
} Season ;
int main() {
    Season season = AUT;
    printf("AUTÊÇ%d\n", season);
    printf("WINÊÇ%d\n", WIN);
    return 0;
}
