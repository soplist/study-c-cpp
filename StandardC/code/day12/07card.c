#include <stdio.h>
#include "compare.h"

extern Card card;

int main() {
    Card aCard;
    ResultType result = 0;
    aCard.type = SI;
    aCard.point = 8;
    card.type = SI;
    card.point = 10;
    result = compare(&aCard);
    if (GT == result) {
        printf("card大\n");
    }
    else if (EQ == result) {
        printf("两副牌相等\n");
    }
    else if (LT == result) {
        printf("card小\n");
    }
    else {
        printf("不能比较\n");
    }
    return 0;
}
