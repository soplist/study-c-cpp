#include <stdio.h>

int sum(int values[], unsigned short num);

int main() {
    int values[3] = {5, 6, 7};
    int result = sum(values, 3);
    printf("求和结果是%d\n", result);
    return 0;
}

//定义函数sum用于完成数组中所有
//变量求和的任务。参数values表示
//要计算的数组，参数num表示数组
//中变量的个数
int sum(int values[], unsigned short num) {
    int loop = 0;
    int result = 0;
    for (loop = 0; loop <= (num - 1); loop++) {
        result += values[loop];
    }
    return result;
}
