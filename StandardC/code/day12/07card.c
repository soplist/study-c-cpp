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
        printf("card��\n");
    }
    else if (EQ == result) {
        printf("���������\n");
    }
    else if (LT == result) {
        printf("cardС\n");
    }
    else {
        printf("���ܱȽ�\n");
    }
    return 0;
}
