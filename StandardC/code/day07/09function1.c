#include <stdio.h>
//����һ���º���add�������
//����x�Ͳ���y���������㲽��
int add(int x, int y) {
    //ʹ��return�ؼ��ֽ���
    //������ִ�в���x + y
    //�ļ�������Ϊ�Ų�����
    //������
    return x + y;
}

int main() {
    //��������value������¼���
    //���
    int value = 0;
    //���ú���add��ɣ���3������
    //���ֵ���͹�����
    //����ͽ����ֵ������value
    value = add(add(2, 3), 4);
    //����ͽ���������Ļ��
    printf("��ͽ����%d\n", value);
    return 0;
}
