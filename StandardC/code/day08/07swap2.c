#include <stdio.h>

void swap(int values[]);

int main() {
   int values[2];
   values[0] = 7;
   values[1] = 13;
   swap(values);
   printf("values[0]是%d\n", values[0]);
   printf("values[1]是%d\n", values[1]);
   return 0;
}

//定义swap函数用于实现两个
//变量数据的交换，参数是一个
//数组，数组中前两个变量
//就是要交换的两个变量。
//函数没有返回值。
void swap(int values[]) {
   int value = 0;
   value = values[0];
   values[0] = values[1];
   values[1] = value;
}




