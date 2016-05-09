#include <stdio.h>
//定义一个新函数add用于完成
//参数x和参数y求和这个计算步骤
int add(int x, int y) {
    //使用return关键字结束
    //函数的执行并把x + y
    //的计算结果作为遗产数据
    //留下来
    return x + y;
}

int main() {
    //声明变量value用来记录求和
    //结果
    int value = 0;
    //调用函数add完成２和3这两个
    //数字的求和工作并
    //把求和结果赋值给变量value
    value = add(add(2, 3), 4);
    //把求和结果输出在屏幕上
    printf("求和结果是%d\n", value);
    return 0;
}
