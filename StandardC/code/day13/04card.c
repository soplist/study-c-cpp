#include <stdio.h>
typedef enum {
    SI,  //这个枚举数据表示单牌
    DO   //这个枚举数据表示对牌
} CardType;

typedef enum {
    GT,  //这个表示大于
    EQ,  //这个表示等于
    LT,  //这个表示小于
    IC   //这个表示不能比较
} ResultType;
typedef struct {
    CardType type;
    unsigned short point;
    ResultType (*pCompare)(const void * pFirstCard, const void * pSecondCard);
} Card ;

ResultType compare(const void * pFCard, const void * pSCard) {
    const Card * pFirstCard = (Card*)pFCard;
    const Card * pSecondCard = (Card*)pSCard;
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
    Card firstCard = {SI, 8, compare};
    Card secondCard = {DO, 10, compare};
    result = firstCard.pCompare(&firstCard, &secondCard);
    if (GT == result) {
        printf("结果是大于\n");
    }
    else if (EQ == result) {
        printf("结果是等于\n");
    }
    else if (LT == result) {
        printf("结果是小于\n");
    }
    else {
        printf("不能比较\n");
    }
    return 0;
}



