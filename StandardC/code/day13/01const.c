#include <stdio.h>
int main() {
    int values[5] = {1, 2, 3, 4, 5};
    /*const int * pValue = values;
    pValue += 3;//编译成功
    pValue[0] = 7;  //编译出错
    */
    /*int * const pValue = values;
    pValue += 3; //编译出错
    pValue[0] = 7; //编译成功
    */
    const int * const pValue = values;
    return 0;
}
