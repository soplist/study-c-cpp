#include <stdio.h>
int add(int x, int y) {
    return x + y;
}

int mul(int x, int y) {
    return x * y;
}

int main() {
    //����һ������ָ�����
    //�����﷨���ƺ�������
    int (*pFunc)(int, int);
    pFunc = add;
    printf("add��%p\n", add);
    printf("pFunc��%p\n", pFunc);
    printf("pFunc(3, 4)��%d\n", pFunc(3, 4));
    pFunc = mul;
    printf("pFunc(3, 4)��%d\n", pFunc(3, 4));
    return 0;
}
