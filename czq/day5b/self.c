#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("�ҵ�id:%d\n",getuid());
	printf("�ҵ���Чid:%d\n",geteuid());
	printf("�ҵĽ���id:%d\n",getpid());
	printf("�ҵĸ�����id:%d\n",getppid());
}
