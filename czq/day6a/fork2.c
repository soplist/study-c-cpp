#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t oid = getpid();
	fork();
	pid_t nid = getpid();
	if(oid==nid){//�����̣��ɽ��̣�
		int i;
		for(i=0; i<10; i++){
			write(1, "*", 1);
			sleep(1);
		}
	}
	else{//�ӽ��̣��½��̣�
		int i;
		for(i=0; i<20; i++){
			write(1, "#", 1);
			sleep(1);
		}
	}
}
