#include "LogSender.h"

LogSender::LogSender(const char *s_ip,int s_port,const char *file,bool linked)
{
    sprintf(ip,"%s",s_ip);
    port=s_port;
    sprintf(failfile,"%s",file);
}

void LogSender::logSend()
{
    readLastFailure();   printf("SEND1>>>\n");
    if(!linked)
    {linkServer();        printf("SEND2>>>>\n");}
    sendLog();           printf("SEND3>>>>>\n");
    saveFailure();       printf("SEND4>>>>>>\n");
}

void LogSender::saveFailure()// throw(Logical View::IOException)
{
   char name[32];
   char ip[257];
   long logintime;
   long logouttime;
   long onlinetime;

   if((*logs).empty()) return;

   int fd=open(failfile,O_WRONLY|O_TRUNC);
    //if(fd==-1)
       //fd=open(loginfile,O_CREAT|O_EXCL);
   list<MLogrec>::iterator it=(*logs).begin();
   while(it!=(*logs).end())
   {
       it->get_log_name(name);
       write(fd,name,sizeof(name));
       it->get_ip(ip);
       write(fd,ip,sizeof(ip));
       logintime=it->get_login_time();
       write(fd,&logintime,sizeof(logintime));
       logouttime=it->get_logout_time();
       write(fd,&logouttime,sizeof(logouttime));
       logintime=it->get_online_time();
       write(fd,&onlinetime,sizeof(onlinetime));
       it++;
   }
   (*logs).clear();
   close(fd);
}


void LogSender::linkServer()// throw(Logical View::LinkException)
{
  fds=socket(PF_INET,SOCK_STREAM,0);
  //if(fd==-1)
  struct sockaddr_in addr;
  addr.sin_family=PF_INET;
  addr.sin_port=htons(port);
  addr.sin_addr.s_addr=inet_addr(ip);
  int r=connect(fds,(struct sockaddr*)&addr,sizeof(addr));
  //if(r==-1)
  linked=true;
}


void LogSender::readLastFailure()// throw(Logical View::IOException)
{
   char name[32];
   char ip[257];
   long logintime;
   long logouttime;
   long onlinetime;

   int fd=open(failfile,O_RDONLY);
   if(fd==-1)
   {
       int fdc=open(failfile,O_CREAT|O_EXCL);
       //if(fdc==-1)
       close(fdc);
       return;
   }
   struct stat st;
   int r=stat(failfile,&st);
   int len=st.st_size/313;
   if(len==0) return;//len为0，则所有都有匹配

   int i;
   for(i=0;i<len;i++)
  {
     lseek(fd,i*313,SEEK_SET);
     read(fd,name,sizeof(name));
     lseek(fd,i*313+32,SEEK_SET);
     read(fd,ip,sizeof(ip));
     lseek(fd,i*313+289,SEEK_SET);
     read(fd,&logintime,sizeof(logintime));
     lseek(fd,i*313+297,SEEK_SET);
     read(fd,&logouttime,sizeof(logouttime));
     lseek(fd,i*313+305,SEEK_SET);
     read(fd,&onlinetime,sizeof(onlinetime));

     MLogrec m(name,ip,logintime,logouttime,onlinetime);
     (*logs).push_back(m);
  }
   close(fd);
}

void LogSender::sendLog()// throw(Logical View::SendException)
{
    char name[32];
    char ip[257];
    long logintime;
    long logouttime;
    long onlinetime;
    int n;

    list<MLogrec>::iterator it=(*logs).begin();
    //假设全部发送成功
    while(it!=(*logs).end())
    {

         it->get_ip(ip);

        //len=strlen(ip);
        //n=send(fds,&len,sizeof(len),0);

        send(fds,ip,sizeof(ip),0);

        it->get_log_name(name);
        n=send(fds,name,sizeof(name),0);
        //if(n==-1)

         //if(n==-1)
        logintime=it->get_login_time();
        send(fds,&logintime,sizeof(logintime),0);
         //if(n==-1)
        logouttime=it->get_logout_time();
        send(fds,&logouttime,sizeof(logouttime),0);
         //if(n==-1)
        onlinetime=it->get_online_time();
        send(fds,&onlinetime,sizeof(onlinetime),0);
         //if(n==-1)
        it=(*logs).erase(it);

        if(strlen(name)==0)
        {printf("*****************************************\n");sleep(1);}

        printf(">>%s, %s, %ld, %ld, %ld\n",name,ip,logintime,logouttime,onlinetime);
    }
}

