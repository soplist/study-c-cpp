#include <stdio.h>

int sum(int values[], unsigned short num);

int main() {
    int values[3] = {5, 6, 7};
    int result = sum(values, 3);
    printf("��ͽ����%d\n", result);
    return 0;
}

//���庯��sum�����������������
//������͵����񡣲���values��ʾ
//Ҫ��������飬����num��ʾ����
//�б����ĸ���
int sum(int values[], unsigned short num) {
    int loop = 0;
    int result = 0;
    for (loop = 0; loop <= (num - 1); loop++) {
        result += values[loop];
    }
    return result;
}
