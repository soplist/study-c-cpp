#include <stdio.h>
#include <string.h>
int main() {
    char firstStr[30];
    char secondStr[30];
    int result = 0;
    printf("�������һ���ַ�����");
    fgets(firstStr, 30, stdin);
    printf("������ڶ����ַ�����");
    fgets(secondStr, 30, stdin);
    //strncmp�������ڱȽ�����
    //�ַ�����ǰ�����ַ��Ĵ�С��
    //����ֵ��һ��
    //���������Ϊ0���ʾ���
    //�������0���ʾǰһ��
    //�ַ��������С��0���ʾ
    //��һ���ַ�����
    result = strncmp(firstStr, secondStr, 5);
    if (0 == result) {
        printf("�ַ������\n");
    }
    else if (result > 0) {
        printf("ǰһ���ַ�����\n");
    }
    else {
        printf("��һ���ַ�����\n");
    }
    return 0;
}
