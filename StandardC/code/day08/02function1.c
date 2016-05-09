#include <stdio.h>
//定义add函数完成任意两个
//整数求和的计算。这个函数
//会返回一个整数作为结果，
//函数执行代码中就必须使用
//return语句明确指定返回的
//数据是哪个
int add(int x, int y) {
    return x + y;
}

//定义函数print完成一个整数
//在屏幕上输出的任务。参数
//就是要输出的这个整数。
void print(int x) {
    printf("%d\n", x);
}

int main() {
    //首先调用add函数完成2＋3的
    //计算，然后再次调用add函数
    //完成5+4的计算，最后调用
    //print函数把计算出的结果9
    //输出到屏幕上
    print(add(add(2, 3), 4));
    return 0;
}
