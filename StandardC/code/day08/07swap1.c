#include <stdio.h>

void swap(int *, int *);

int main() {
    int firstValue = 7;
    int secondValue = 13;
    swap(&firstValue, &secondValue);
    printf("firstValue是%d\n", firstValue);
    printf("secondValue是%d\n", secondValue);
    return 0;
}

//swap函数用于交换两个变量的
//数值，参数是两个指针变量分别
//记录某个变量的地址，函数没有
//返回值
void swap(int * pFirstValue, int * pSecondValue) {
    int value = 0;
    value = *pFirstValue;
    *pFirstValue = *pSecondValue;
    *pSecondValue = value;
}





