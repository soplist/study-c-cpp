#include <stdio.h>
#include <string.h>
int main() {
    char firstStr[30];
    char secondStr[30];
    printf("�������һ���ַ�����");
    fgets(firstStr, 30, stdin);
    //strcpy������������ַ���
    //��������һ��������Ŀ��
    //����ĵ�ַ���ڶ�������
    //��ԭʼ�ַ����ĵ�ַ�����
    //Ŀ������Ŀռ䲻���п���
    //������⡣
    strcpy(secondStr, firstStr);
    printf("�ַ�����%s\n", secondStr);
    return 0;
}
