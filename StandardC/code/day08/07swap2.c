#include <stdio.h>

void swap(int values[]);

int main() {
   int values[2];
   values[0] = 7;
   values[1] = 13;
   swap(values);
   printf("values[0]��%d\n", values[0]);
   printf("values[1]��%d\n", values[1]);
   return 0;
}

//����swap��������ʵ������
//�������ݵĽ�����������һ��
//���飬������ǰ��������
//����Ҫ����������������
//����û�з���ֵ��
void swap(int values[]) {
   int value = 0;
   value = values[0];
   values[0] = values[1];
   values[1] = value;
}




