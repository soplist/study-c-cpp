#ifndef __COMPARE_H__
#define __COMPARE_H__
typedef enum {SI, DO} CardType ;
typedef enum {GT, EQ, LT, IC} ResultType;
typedef struct {
   CardType type;
   unsigned short point;
}Card;
ResultType compare(const Card* pCard) ;
#endif  //__COMPARE_H__
