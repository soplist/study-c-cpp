#include <stdio.h>
//定义阶乘函数完成某个数字
//阶乘的计算。参数num就是需要
//计算阶乘的数字，返回值就是
//计算的结果
int jiecheng(int num) {
   //控制代码保证当参数为1的时候
   //不会发起下一次调用
   if (1 == num) {
       return 1;
   }
   else {
       return jiecheng(num - 1) * num;
   }
}

int main() {
    int value = 0;
    printf("请输入需要计算阶乘的数字：");
    scanf("%d", &value);
    printf("数字%d的阶乘是%d\n", value, jiecheng(value));
    return 0;
}



