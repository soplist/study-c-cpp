#include <unistd.h>
#include <stdio.h>

int main()
{
	puts("hello");//ֻ��һ�ݽ���
	printf("world ");//�����ڻ�������
	int oldpid = getpid();
	sleep(5);
	fork();//���ƽ��̣�������Ҳ�ᱻ����
	puts("csd1208");//�Ѿ������ݽ�����
	int pid = getpid();
	printf("oldpid=%d,pid=%d\n",oldpid,pid);
	return 0;
}
