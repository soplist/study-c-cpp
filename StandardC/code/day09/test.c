#include <stdio.h>
void fab() {
   static int values[100] = {0, 1};
   printf("values[2]ÊÇ%d\n", values[2]);
   values[2] = 3;
}

int main() {
   fab();
   fab();
   return 0;
}
