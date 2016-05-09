#include <stdio.h>
#include <string.h>
int main() {
    char * strs[5] = {"japan", "china", "america", "britain", "australia"};
    int outloop = 0;
    int inloop = 0;
    for (outloop = 0; outloop <= 3; outloop++) {
        for (inloop = outloop + 1; inloop <= 4; inloop++) {
           if (strcmp(strs[outloop], strs[inloop]) > 0) {
              char * pStr = strs[outloop];
              strs[outloop] = strs[inloop];
              strs[inloop] = pStr;
           }
        }
    }
    for (outloop = 0; outloop <= 4; outloop++) {
       printf("%s\n", strs[outloop]);
   }
    return 0;
}
