#include <stdio.h>
#define GREATTHAN       1
#define EQUAL           0
#define LESSTHAN        -1
#define INCOMPATIBLE    -2
#define SINGLE          1
#define DOUBLE          2
#define SERIAL          3
#define SAMESERIAL      4
typedef struct {
   unsigned short type;
   unsigned short point;
   unsigned short start;
   unsigned short len;
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
   else if (DOUBLE == firstCard.type) {
      if (DOUBLE == secondCard.type) {
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
   else if (SERIAL == firstCard.type) {
      if (SERIAL == secondCard.type) {
         if (firstCard.len == secondCard.len) {
            if (firstCard.start > secondCard.start) {
               return GREATTHAN;
            }
            else if (firstCard.start == secondCard.start) {
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
      else if (SAMESERIAL == secondCard.type) {
         if (firstCard.len == secondCard.len) {
            return LESSTHAN;
         }
         else {
            return INCOMPATIBLE;
         }
      }
      else {
         return INCOMPATIBLE;
      }
   }
   else {
       if (SERIAL == secondCard.type) {
          if (firstCard.len == secondCard.len) {
             return GREATTHAN;
          }
          else {
             return INCOMPATIBLE;
          }
       }
       else if (SAMESERIAL == secondCard.type) {
          if (firstCard.start > secondCard.start) {
             return GREATTHAN;
          }
          else if (firstCard.start == secondCard.start) {
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
}

int main() {
    int result = 0;
    Card firstCard;
    Card secondCard;
    firstCard.type = SERIAL;
    firstCard.start = 5;
    firstCard.len = 5;
    secondCard.type = SERIAL;
    secondCard.start = 6;
    secondCard.len = 5;
    result = compare(firstCard, secondCard);
    switch(result) {
    case GREATTHAN:
        printf("第一副牌大\n");
        break;
    case EQUAL:
        printf("两副牌一样大\n");
        break;
    case LESSTHAN:
        printf("第一副牌小\n");
        break;
    default:
        printf("他们之间没法比较\n");
    }
    return 0;
}





