#include <stdio.h>
//����׳˺������ĳ������
//�׳˵ļ��㡣����num������Ҫ
//����׳˵����֣�����ֵ����
//����Ľ��
int jiecheng(int num) {
   //���ƴ��뱣֤������Ϊ1��ʱ��
   //���ᷢ����һ�ε���
   if (1 == num) {
       return 1;
   }
   else {
       return jiecheng(num - 1) * num;
   }
}

int main() {
    int value = 0;
    printf("��������Ҫ����׳˵����֣�");
    scanf("%d", &value);
    printf("����%d�Ľ׳���%d\n", value, jiecheng(value));
    return 0;
}



