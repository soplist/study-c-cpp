#include <stdio.h>
int main() {
    int values[5] = {1, 2, 3, 4, 5};
    /*const int * pValue = values;
    pValue += 3;//����ɹ�
    pValue[0] = 7;  //�������
    */
    /*int * const pValue = values;
    pValue += 3; //�������
    pValue[0] = 7; //����ɹ�
    */
    const int * const pValue = values;
    return 0;
}
