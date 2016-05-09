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
               每次循环负责完成
                当前列举到编号
               的数字的计算。在
               执行的时候假设
               firstFab和secondFab
               中记录了数列中前
               两个数字。
            */
            unsigned short temp = 0;
            temp = firstFab + secondFab;
            //为下次循环作准备
            //保证firstFab和
            //secondFab变量中
            //记录了下次循环所
            //需要的数字
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
    printf("请输入数字编号："); 
    scanf("%hu", &num);
    printf("编号为%hu的数字是%hu\n", num, fab(num));
    return 0;
}
