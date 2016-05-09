#include <stdio.h>

//定义函数prime_number用于测试
//某个整数是不是素数。这个函数
//的参数就是待测试的数据，返回值
//表示测试结果。0表示不是素数，
//1表示是素数
int prime_number(int value) {
    int upper = value / 2;
    int loop = 0;
    //依次列举从2到value / 2之间
    //的每一个整数，如果有任何
    //一个可以把value整除则说明
    //value不是素数，否则就说明
    //value是素数
    for (loop = 2; loop <= upper; loop++) {
        if (0 == (value % loop)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int value = 0;
    int ret = 0;
    printf("请输入待测试的整数：");
    scanf("%d", &value);
    ret = prime_number(value);
    if (ret != 0) {
        printf("数字%d是素数\n", value);
    }
    else {
        printf("数字%d不是素数\n", value);
    }
    return 0;
}




