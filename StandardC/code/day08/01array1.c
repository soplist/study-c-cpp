#include <stdio.h>
int main() {
    //��������num������¼�û�
    //��������ָ���
    unsigned short num = 0;
    //��������loop������Ϊѭ��
    //����
    int loop = 0;
    //�����ʾ��Ϣ
    printf("���������ֵĸ�����");
    //���û���������ָ�����¼��
    //����num��
    scanf("%hu", &num);
    //ʹ��num������������values
    //�����б����ĸ�������ǰ��
    //�û���������־�����
    unsigned short values[num];
    //ʹ��һ��forѭ�������о�
    //������ÿ���������±�
    for (loop = 0; loop <= (num - 1); loop++) {
        //��ѭ���������û�����
        //���ֲ���¼�ڵ�ǰ�о�
        //���ı�����
        printf("�������%d�����֣�", (loop + 1));
        scanf("%hu", &values[loop]);
    } 
    //ʹ��һ��forѭ���Ӻ���ǰ
    //�����о�ÿ���������±�
    for (loop = (num - 1); loop >= 0; loop--) {
        //��ѭ���аѵ�ǰ�оٵ���
        //�����������Ļ��
        printf("values[%d]��%hu\n", loop, values[loop]);
    }
    return 0;
}
