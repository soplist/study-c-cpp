#include <stdio.h>
int main() {
    //声明变量num用来记录用户
    //输入的数字个数
    unsigned short num = 0;
    //声明变量loop用来作为循环
    //变量
    int loop = 0;
    //输出提示信息
    printf("请输入数字的个数：");
    //把用户输入的数字个数记录在
    //变量num中
    scanf("%hu", &num);
    //使用num变量声明数组values
    //数组中变量的个数是由前面
    //用户输入的数字决定的
    unsigned short values[num];
    //使用一个for循环依次列举
    //数组中每个变量的下标
    for (loop = 0; loop <= (num - 1); loop++) {
        //在循环中请求用户输入
        //数字并记录在当前列举
        //到的变量中
        printf("请输入第%d个数字：", (loop + 1));
        scanf("%hu", &values[loop]);
    } 
    //使用一个for循环从后向前
    //依次列举每个变量的下标
    for (loop = (num - 1); loop >= 0; loop--) {
        //在循环中把当前列举到的
        //变量输出在屏幕上
        printf("values[%d]是%hu\n", loop, values[loop]);
    }
    return 0;
}
