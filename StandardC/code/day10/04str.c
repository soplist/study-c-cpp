#include <stdio.h>
int main() {
    char str[10]; 
    printf("������һ���ַ�����");
    fgets(str, 10, stdin);
    printf("�ַ�����%s\n", str);
    return 0;
}
