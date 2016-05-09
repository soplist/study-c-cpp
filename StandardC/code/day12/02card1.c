#include <stdio.h>
#define SINGLE        1
#define DOUBLE        2
#define GREATTHAN     1
#define EQUAL         2
#define LESSTHAN      -1
#define INCOMPATIBLE  -2
typedef struct {
   unsigned short type;
   unsigned short point;
} Card ;
int compare(Card firstCard, Card secondCard) {
   if (SINGLE == firstCard.type) {
      if (SINGLE == secondCard.type) {
         if (firstCard.point > secondCard.point) {
            return GREATTHAN;
         }
         else if (firstCard.point == secondCard.point) {
            return EQUAL;
         }
         else {
            return LESSTHAN;
         }
      }
      else {
            return INCOMPATIBLE;
      }
   }
   else {
      if (SINGLE == secondCard.type) {
         return INCOMPATIBLE;
      }
      else {
         if (firstCard.point > secondCard.point) {
            return GREATTHAN;
         }
         else if (firstCard.point == secondCard.point) {
            return EQUAL;
         }
         else {
            return LESSTHAN;
         }
      }
   }
}
int main() {
    int result = 0;
    Card firstCard;
    Card secondCard;
    firstCard.type = SINGLE;
    firstCard.point = 10;
    secondCard.type = SINGLE;
    secondCard.point = 8;
    result = compare(firstCard, secondCard);
    if (GREATTHAN == result) {
       printf("第一副牌大\n");
    }
    else if (EQUAL == result) {
       printf("两副牌一样大\n");
    }
    else if (LESSTHAN == result) {
       printf("第一副牌小\n");
    }
    else {
       printf("不能比较\n");
    }
    return 0;
}
