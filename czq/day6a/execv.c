#include <stdio.h>
#include <stdlib.h>

int main()
{
	puts("begin========");
	char* argv[]={"/usr/bin/cal","8","2012",NULL};
	if(fork()==0)//�ӽ���
		execv("/usr/bin/cal",argv);//���ǵ�ǰ����ȫ������
	else//������
		puts("end=========");//(û)�л���ִ��
}
