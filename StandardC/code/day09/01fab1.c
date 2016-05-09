#include <stdio.h>
//定义递归函数fab完成
//菲式数列的计算，参数
//是数字编号，返回值是
//计算结果
unsigned short fab(unsigned short num) {
    if (0 == num) {
        return 0;
    }
    else if (1 == num) {
        return 1;
    }
    else {
        return fab(num - 2) + fab(num - 1);
    }
}

int main() {
    unsigned short num = 0;
    printf("请输入编号：");
    scanf("%hu", &num);
    printf("fab(%hu)是%hu\n", num, fab(num));
    return 0;
}
