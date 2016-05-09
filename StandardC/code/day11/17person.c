#include <stdio.h>
struct IPhone {
   float inPrice;
   float outPrice;
};
int main() {
    struct IPhone phones[3];
    printf("请输入手机的进价：");
    scanf("%f", &(phones[0].inPrice));
    printf("请输入手机的出价：");
    scanf("%f", &(phones[0].outPrice));
    printf("进价是%f\n", phones[0].inPrice);
    printf("出价是%f\n", phones[0].outPrice);
    return 0;
}
