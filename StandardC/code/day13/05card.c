#include <stdio.h>
typedef enum {
    SI,  //���ö�����ݱ�ʾ����
    DO   //���ö�����ݱ�ʾ����
} CardType;

typedef enum {
    GT,  //�����ʾ����
    EQ,  //�����ʾ����
    LT,  //�����ʾС��
    IC   //�����ʾ���ܱȽ�
} ResultType;
typedef struct {
    CardType type;
    unsigned short point;
    ResultType (*pCompare)(const void * pFirstCard, const void * pSecondCard);
} Card ;

//������������Ƚ�һ������
//������һ���ƵĴ�С
ResultType sCompare(const void * pFCard, const void * pSCard) {
    Card *pFirstCard = (Card *)pFCard;
    Card *pSecondCard = (Card *)pSCard;
    if (SI != pFirstCard->type) {
        return IC;
    }
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

//��������������һ������
//������һ����֮��Ĵ�С�Ƚ�
ResultType dCompare(const void * pFCard, const void * pSCard) {
    Card * pFirstCard = (Card *)pFCard;
    Card * pSecondCard = (Card *)pSCard;
    if (DO != pFirstCard->type) {
        return IC;
    }
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
    Card firstCard = {SI, 8, sCompare};
    Card secondCard = {SI, 10, sCompare};
    result = firstCard.pCompare(&firstCard, &secondCard);
    if (GT == result) {
        printf("����Ǵ���\n");
    }
    else if (EQ == result) {
        printf("����ǵ���\n");
    }
    else if (LT == result) {
        printf("�����С��\n");
    }
    else {
        printf("���ܱȽ�\n");
    }
    return 0;
}



