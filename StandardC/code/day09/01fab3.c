#include <stdio.h>
//ȫ������values������¼
//�����Ѿ������������
//����
unsigned short values[100] = {0, 1};
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
        //�ڼ�����Ϊnum������
        //����֮ǰ�Ȳ�ѯ���飬
        //��������м�¼�����
        //���־�ֱ���ǹ����ã�
        //�����ȥ���㡣ע��
        //�����Ҫ�ѽ����¼��
        //������
        if (0 == values[num]) {
            values[num] = fab(num - 2) + fab(num - 1);
        }
        return values[num];
    }
}

int main() {
    unsigned short num = 0;
    printf("�������ţ�");
    scanf("%hu", &num);
    printf("fab(%hu)��%hu\n", num, fab(num));
    return 0;
}
