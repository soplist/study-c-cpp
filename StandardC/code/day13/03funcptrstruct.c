#include <stdio.h>
//����ṹPerson��������
//�ˣ����а�����һ������
//ָ��������ʾ��ǰ����˵�
//������ʽ
typedef struct {
    unsigned short age;
    //��pGrow����ָ���¼
    //ÿ�����Լ���������ʽ
    void (*pGrow)(void * pPerson);
} Person ;

//�����˵�������ʽ������
//20����21�������Ǵ�����
//ĳ���˵Ľṹ��ָ��
void grow(void * pPer) {
    Person *pPerson = (Person*)pPer;
    pPerson->age++;
}

//ʹ����ĳ��ױƷ���������ʽ��
//����20����18
void grow1(void * pPer) {
    Person *pPerson = (Person*)pPer;
    pPerson->age -= 2;
}

int main() {
    //���������ṹ��ֱ����
    //������ͬ���ˣ�ÿ���ṹ
    //���¼�Լ����е�����
    //��ʽ
    Person firstPerson = {20, grow};
    Person secondPerson = {20, grow1};
    //ÿ����ʹ���Լ�������
    //��ʽ����һ��
    firstPerson.pGrow(&firstPerson);
    secondPerson.pGrow(&secondPerson);
    //�������������ֱ����
    //����Ļ��
    printf("firstPerson.age��%hu\n", firstPerson.age);
    printf("secondPerson.age��%hu\n", secondPerson.age);
    return 0;
}





