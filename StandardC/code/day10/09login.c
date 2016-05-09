#include <stdio.h>
#include <string.h>
#include <time.h>
int main() {
    int code = 0;
    int inputcode = 0;
    char usrName[] = "user\n";
    char usr[30];
    char pwd[] = "123456\n";
    char password[30];
    srand(time(0));
    code = rand() % 10000;
    printf("验证码是：%d\n", code);
    printf("请输入用户名：");
    fgets(usr, 30, stdin);
    if (0 != strcmp(usr, usrName)) {
        printf("用户名错误\n");
        return 0;
    }
    printf("请输入用户密码：");
    fgets(password, 30, stdin);
    if (0 != strcmp(pwd, password)) {
        printf("用户密码错误\n");
        return 0;
    }
    printf("请输入验证码：");
    scanf("%d", &inputcode);
    if (code != inputcode) {
        printf("验证码错误\n");
        return 0;
    }
    printf("登录成功\n");
    return 0;
}
