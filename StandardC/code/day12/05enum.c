#include <stdio.h>
typedef enum {
   SPR, 
   SUM, 
   AUT = 3, 
   WIN
} Season ;
int main() {
    Season season = AUT;
    printf("AUT��%d\n", season);
    printf("WIN��%d\n", WIN);
    return 0;
}
