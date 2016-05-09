#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
	char cmd[1000];
	puts("欢迎使用MyShell!");
	for(;;){
		printf("ms>");
		scanf(" %[^\n]", cmd);
		if(strcmp(cmd,"furong")==0)
			break;
		if(strncmp(cmd,"cd ",3)==0)//cmd是cd命令)
			//"cd abc"
			chdir(cmd+3);//调用chdir(目录);
		else
			system(cmd);
	}
	puts("谢谢!");
}
