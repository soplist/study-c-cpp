#include <stdio.h>
int main() {
    printf("�кţ�%d\n", __LINE__);
    printf("�ļ���%s\n", __FILE__);
    printf("���ڣ�%s\n", __DATE__);
    printf("ʱ�䣺%s\n", __TIME__);
    printf("%sC��׼\n", __STDC__?"����":"������");
    return 0;
}
