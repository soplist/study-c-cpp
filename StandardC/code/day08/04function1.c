#include <stdio.h>
//����add����������ʾ��������
//����ֵ�͵�ַ
int add(int x, int y) {
    printf("add�����б���x�ĵ�ַ��%p\n", &x);
    printf("add�����б���x����ֵ��%d\n", x);
    return x + y;
}

int main() {
    //��������x��Ȼ���������
    //�����ĵ�ַ�����ݣ�����
    //��add�����е�x�������Ƚ�
    //��֤��������������ȫ��ͬ��
    //����
    int x = 4;
    printf("main������x�����ĵ�ַ��%p\n", &x);
    printf("main������x��������ֵ��%d\n", x);
    int y = 5;
    add(x, y);
    return 0;
}
