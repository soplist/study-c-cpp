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
    printf("��֤���ǣ�%d\n", code);
    printf("�������û�����");
    fgets(usr, 30, stdin);
    if (0 != strcmp(usr, usrName)) {
        printf("�û�������\n");
        return 0;
    }
    printf("�������û����룺");
    fgets(password, 30, stdin);
    if (0 != strcmp(pwd, password)) {
        printf("�û��������\n");
        return 0;
    }
    printf("��������֤�룺");
    scanf("%d", &inputcode);
    if (code != inputcode) {
        printf("��֤�����\n");
        return 0;
    }
    printf("��¼�ɹ�\n");
    return 0;
}
