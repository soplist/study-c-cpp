#include <stdio.h>
//�ݹ麯��love�������Ұ���
//��������һ���ź�������
//��ʾ���м���û�к�
void love(int num) {
    if (num > 0) {
        printf("�Ұ���\n");
        love(num - 1);
    }
}

int main() {
    int loop = 0;
    love(5);
    return 0;
}
