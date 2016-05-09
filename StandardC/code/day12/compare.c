#include <stdio.h>
#include "compare.h"

Card card;

ResultType compare(const Card *pCard) {
    if (SI == card.type) {
        if (SI == pCard->type) {
            if (card.point > pCard->point) {
               return GT;
            }
            else if (card.point == pCard->point) {
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
        if (DO == pCard->type) {
           if (card.point > pCard->point) {
              return GT;
           }
           else if (card.point == pCard->point) {
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
}
