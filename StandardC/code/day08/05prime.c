#include <stdio.h>

//���庯��prime_number���ڲ���
//ĳ�������ǲ����������������
//�Ĳ������Ǵ����Ե����ݣ�����ֵ
//��ʾ���Խ����0��ʾ����������
//1��ʾ������
int prime_number(int value) {
    int upper = value / 2;
    int loop = 0;
    //�����оٴ�2��value / 2֮��
    //��ÿһ��������������κ�
    //һ�����԰�value������˵��
    //value���������������˵��
    //value������
    for (loop = 2; loop <= upper; loop++) {
        if (0 == (value % loop)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int value = 0;
    int ret = 0;
    printf("����������Ե�������");
    scanf("%d", &value);
    ret = prime_number(value);
    if (ret != 0) {
        printf("����%d������\n", value);
    }
    else {
        printf("����%d��������\n", value);
    }
    return 0;
}




