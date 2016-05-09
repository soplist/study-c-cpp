#include <stdio.h>
//全局数组values用来记录
//所有已经计算过的数列
//数据
unsigned short values[100] = {0, 1};
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
        //在计算编号为num的数列
        //数据之前先查询数组，
        //如果数组中记录了这个
        //数字就直接那过来用，
        //否则才去计算。注意
        //计算后要把结果记录到
        //数组中
        if (0 == values[num]) {
            values[num] = fab(num - 2) + fab(num - 1);
        }
        return values[num];
    }
}

int main() {
    unsigned short num = 0;
    printf("请输入编号：");
    scanf("%hu", &num);
    printf("fab(%hu)是%hu\n", num, fab(num));
    return 0;
}
