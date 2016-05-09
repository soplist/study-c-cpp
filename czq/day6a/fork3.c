#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("letter",O_CREAT|O_WRONLY,0644);
	//if(fd<0)...
	if(fork()>0){//¸¸½ø³Ì
		char c;
		for(c='a'; c<='z'; c++){
			write(fd, &c, 1);
			sleep(1);
		}
		close(fd);
	}
	else{
		char c;
		for(c='A'; c<='Z'; c++){
			write(fd, &c, 1);
			sleep(1);
		}
		close(fd);
	}
}
