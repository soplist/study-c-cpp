#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
	char cmd[1000];
	puts("��ӭʹ��MyShell!");
	for(;;){
		printf("ms>");
		scanf(" %[^\n]", cmd);
		if(strcmp(cmd,"furong")==0)
			break;
		if(strncmp(cmd,"cd ",3)==0)//cmd��cd����)
			//"cd abc"
			chdir(cmd+3);//����chdir(Ŀ¼);
		else
			system(cmd);
	}
	puts("лл!");
}
