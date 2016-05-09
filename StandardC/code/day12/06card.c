#include <stdio.h>
typedef enum {SI, DO} CardType;
typedef enum {GT, EQ, LT, IC} ResultType;
typedef struct {
   CardType type;
   unsigned short point;
} Card ;
ResultType compare(const Card *pFirstCard, const Card *pSecondCard) {
   if (SI == pFirstCard->type) {
      if (SI == pSecondCard->type) {
         if (pFirstCard->point > pSecondCard->point) {
            return GT;
         }
         else if (pFirstCard->point == pSecondCard->point) {
            return EQ;
         }
         else {
            return LT;
         }
      }
      else {
            return IC;
      }
   }
   else {
      if (SI == pSecondCard->type) {
         return IC;
      }
      else {
         if (pFirstCard->point > pSecondCard->point) {
            return GT;
         }
         else if (pFirstCard->point == pSecondCard->point) {
            return EQ;
         }
         else {
            return LT;
         }
      }
   }
}
int main() {
    ResultType result = 0;
    Card firstCard;
    Card secondCard;
    firstCard.type = SI;
    firstCard.point = 10;
    secondCard.type = SI;
    secondCard.point = 8;
    result = compare(&firstCard, &secondCard);
    if (GT == result) {
       printf("��һ���ƴ�\n");
    }
    else if (EQ == result) {
       printf("������һ����\n");
    }
    else if (LT == result) {
       printf("��һ����С\n");
    }
    else {
       printf("���ܱȽ�\n");
    }
    return 0;
}
