#include <stdio.h>
#include <string.h>
int main() {
    char firstStr[20] = "abc";
    char secondStr[] = "xyz";
    //strcat�������԰�secondStr
    //������firstStr�ַ������
    //firstStr��һ��ҪԤ���㹻
    //�Ŀռ�
    strcat(firstStr, secondStr);
    printf("����ַ�����%s\n", firstStr);
    return 0;
}
