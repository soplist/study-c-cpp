#include <stdio.h>
typedef struct {
   unsigned short type;
   unsigned short point;
   unsigned short start;
   unsigned short len;
} FirstCard;

typedef struct {
   int type:2;
   int point:4;
   int start:4;
   int len:4;
} SecondCard;
int main() {
   printf("sizeof(FirstCard)ÊÇ%d\n", sizeof(FirstCard));
   printf("sizeof(SecondCard)ÊÇ%d\n", sizeof(SecondCard));
   return 0;
}
