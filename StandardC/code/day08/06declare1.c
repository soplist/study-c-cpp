#include <stdio.h>

//��һ���Ǻ������������ǰ�
//�����еĴ�����ʡ�Ե��Ժ�
//�õ���
int add(int , int );

int main() {
    printf("add(2, 3)��%d\n", add(2, 3));
    return 0;
}

int add(int x, int y) {
    return x + y;
}
