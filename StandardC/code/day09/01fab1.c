#include <stdio.h>
//����ݹ麯��fab���
//��ʽ���еļ��㣬����
//�����ֱ�ţ�����ֵ��
//������
unsigned short fab(unsigned short num) {
    if (0 == num) {
        return 0;
    }
    else if (1 == num) {
        return 1;
    }
    else {
        return fab(num - 2) + fab(num - 1);
    }
}

int main() {
    unsigned short num = 0;
    printf("�������ţ�");
    scanf("%hu", &num);
    printf("fab(%hu)��%hu\n", num, fab(num));
    return 0;
}
