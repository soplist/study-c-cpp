#include <stdio.h>
#include <stdlib.h>
int main() {
    unsigned short num = 0;
    unsigned short *pValue = NULL;
    printf("���������ָ�����");
    scanf("%hu", &num);
    //ʹ����������Ӷ���
    //�������
    pValue = (unsigned short*)malloc(num * sizeof(unsigned short));
    //ʹ����������Ѵ�
    //���з���ı�������
    //�����
    free(pValue);
    return 0;
}
