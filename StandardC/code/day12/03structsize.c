#include <stdio.h>
typedef struct {
   char firstChar;
   char secondChar;
   int value;
} FirstStruct ;

typedef struct {
   char firstChar;
   int value;
   char secondChar;
} SecondStruct ;
int main() {
   printf("sizeof(FirstStruct)��%d\n", sizeof(FirstStruct));
   printf("sizeof(SecondStruct)��%d\n", sizeof(SecondStruct));
   return 0;
}





