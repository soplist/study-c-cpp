#include <stdio.h>
struct IPhone {
   float inPrice;
   float outPrice;
};
int main() {
    struct IPhone phones[3];
    printf("�������ֻ��Ľ��ۣ�");
    scanf("%f", &(phones[0].inPrice));
    printf("�������ֻ��ĳ��ۣ�");
    scanf("%f", &(phones[0].outPrice));
    printf("������%f\n", phones[0].inPrice);
    printf("������%f\n", phones[0].outPrice);
    return 0;
}
