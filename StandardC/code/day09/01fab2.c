#include <stdio.h>
unsigned short fab(unsigned short num) {
    if (0 == num) {
        return 0;
    }
    else if (1 == num) {
        return 1;
    }
    else {
        unsigned short firstFab = 0;
        unsigned short secondFab = 1;
        unsigned short loop = 0;
        for (loop = 2; loop <= num; loop++) {
            /*
               ÿ��ѭ���������
                ��ǰ�оٵ����
               �����ֵļ��㡣��
               ִ�е�ʱ�����
               firstFab��secondFab
               �м�¼��������ǰ
               �������֡�
            */
            unsigned short temp = 0;
            temp = firstFab + secondFab;
            //Ϊ�´�ѭ����׼��
            //��֤firstFab��
            //secondFab������
            //��¼���´�ѭ����
            //��Ҫ������
            firstFab = secondFab;
            secondFab = temp;
            /*secondFab += firstFab;
            firstFab = secondFab - firstFab;*/
        }
        return secondFab;
    }
}

int main() {
    unsigned short num = 0;
    printf("���������ֱ�ţ�"); 
    scanf("%hu", &num);
    printf("���Ϊ%hu��������%hu\n", num, fab(num));
    return 0;
}
