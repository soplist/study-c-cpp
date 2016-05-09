#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <ctime>

int main()
{
  int fd=socket(PF_INET,SOCK_STREAM,0);
  if(fd==-1) perror("SOCKET"),exit(-1);
  struct sockaddr_in addr;
  addr.sin_family=PF_INET;
  addr.sin_port=htons(9999);
  inet_aton("192.168.244.134",&addr.sin_addr);
  int r=bind(fd,(struct sockaddr *)&addr,sizeof(addr));
  if(r==-1) perror("bind"),exit(-1);

  printf("start>>>\n");

  listen(fd,10);
  int cfd=accept(fd,0,0);

  char name[32];
  char ip[257];
  long logintime;
  long logouttime;
  long onlinetime;


  int i=1;
  while(1)
  {
     r=recv(cfd,ip,sizeof(ip),MSG_WAITALL);
    ip[r]=0;

    if(r==0) break;
    r=recv(cfd,name,sizeof(name),MSG_WAITALL);
    name[r]=0;

    r=recv(cfd,&logintime,sizeof(logintime),MSG_WAITALL);
    r=recv(cfd,&logouttime,sizeof(logouttime),MSG_WAITALL);
    r=recv(cfd,&onlinetime,sizeof(onlinetime),MSG_WAITALL);

    //int in=(int)logintime;
    char intime[32];
    sprintf(intime,"%s",ctime((time_t *)(&logintime)));
    //int out=(int)logouttime;
    char outtime[32];
    sprintf(outtime,"%s",ctime((time_t *)(&logouttime)));

    printf("%d>>%s, %s, %s ,%s, %ld\n",i++,name,ip,intime,outtime,onlinetime);

  }
  close(cfd);
  close(fd);
}
