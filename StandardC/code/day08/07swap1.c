#include <stdio.h>

void swap(int *, int *);

int main() {
    int firstValue = 7;
    int secondValue = 13;
    swap(&firstValue, &secondValue);
    printf("firstValue��%d\n", firstValue);
    printf("secondValue��%d\n", secondValue);
    return 0;
}

//swap�������ڽ�������������
//��ֵ������������ָ������ֱ�
//��¼ĳ�������ĵ�ַ������û��
//����ֵ
void swap(int * pFirstValue, int * pSecondValue) {
    int value = 0;
    value = *pFirstValue;
    *pFirstValue = *pSecondValue;
    *pSecondValue = value;
}





