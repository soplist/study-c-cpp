#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    unsigned short value = 0;
    unsigned short guess = 0;
    //ʹ��time�������һ��ʱ��
    //���ݲ�������Ϊ��������
    //���������
    srand(time(0));
    value = rand() % 100;
    do {
        printf("������²����ݣ�");
        scanf("%hu", &guess);
        if (guess > value) {
           printf("�´���\n");
        }
        else if (guess < value) {
           printf("��С��\n");
        }
        else {
           printf("�¶���\n");
        }
    } while(guess != value);
}
