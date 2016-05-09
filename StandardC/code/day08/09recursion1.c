#include <stdio.h>
//递归函数love用来喊我爱你
//并发起下一次呐喊，参数
//表示还有几次没有喊
void love(int num) {
    if (num > 0) {
        printf("我爱你\n");
        love(num - 1);
    }
}

int main() {
    int loop = 0;
    love(5);
    return 0;
}
