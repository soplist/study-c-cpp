#include "LogReader.h"

LogReader::LogReader(const char *lfile,const char *bfile,const char *linfile)
{
   sprintf(logfile,"%s",lfile);//日志文件
   sprintf(backfile,"%s",bfile);//备份日志文件
   sprintf(loginfile,"%s",linfile);//未匹配日志文件
}

void LogReader::logRead() //throw(Logical View::LogReadException)
{
    readLogins();        printf("READ1>>>\n");
    readLog();           printf("READ2>>>>\n");
    matchLog();          printf("READ3>>>>>\n");
    saveLogins();        printf("READ4>>>>>>\n");
}


void LogReader::backupLog() //throw(Logical View::BackException)
{
   struct stat st;
   int r=stat(logfile,&st);
   int len=st.st_size;
   //if(r==-1)
   int fdl=open(logfile,O_RDONLY);
   //if(fdl==-1)
   char buf[len];
   r=read(fdl,buf,len);
   //if(r==-1)
   int fdb=open(backfile,O_WRONLY|O_CREAT|O_EXCL);
   //if(fdb==-1)
   r=write(fdb,buf,len);
   //if(r==-1)
   close(fdl);
   close(fdb);
   fdl=open(logfile,O_RDONLY|O_TRUNC);
   //if(fdl==-1)
   close(fdl);
}

void LogReader::readLog() //throw(Logical View::ReadException)
{
   char name[32];
   char ip[257];
   int t;
   long time;
   short entry;
   //int exit;
   pid_t pid;

   struct stat st;
   int r=stat(logfile,&st);
   int len=st.st_size/372;

   int fd=open(logfile,O_RDONLY);
    //if(fd==-1)
   int i;
   for(i=0;i<len;i++)
   {
     lseek(fd,i*372,SEEK_SET);
     read(fd,name,sizeof(name));
     lseek(fd,i*372+36,SEEK_CUR);
     read(fd,&pid,sizeof(pid));
     lseek(fd,i*372+0,SEEK_CUR);
     read(fd,&entry,sizeof(entry));
     lseek(fd,i*372+6,SEEK_CUR);
     read(fd,&t,sizeof(t));
     lseek(fd,i*372+30,SEEK_CUR);
     read(fd,ip,sizeof(ip));

     entry=entry>>8&0xff|entry<<8&0xff00;
     time=t>>24&0xff|t>>8&0xff00|t<<8&0xff0000|t<<24&0xff000000;
     pid=pid>>24&0xff|pid>>8&0xff00|pid<<8&0xff0000|pid<<24&0xff000000;


    // printf("%s,%ld,%d,%s\n",name,time,pid,ip);
    // if(i==200) exit(0);


     Logrec l(name,ip,time,pid);
     if(entry==7)
     {
         logins.push_back(l);
         /*
         char sname[32];(logins.rbegin())->get_log_name(sname);
         char sip[257];(logins.rbegin())->get_log_ip(sip);
         printf("%d,%s,%s  ",(logins.rbegin())->get_pid(),sip,sname);
         */
     }
     else if(entry==8)
     {
         logouts.push_back(l);
         /*
         char sname[32];(logouts.rbegin())->get_log_name(sname);
         char sip[257];(logouts.rbegin())->get_log_ip(sip);
         printf("%d,%s,%s  ",(logouts.rbegin())->get_pid(),sip,sname);
         */
     }
   }
   printf("logins->%d,logouts->%d\n",logins.size(),logouts.size());
   close(fd);
}

void LogReader::matchLog()
{
   list<Logrec>::iterator itin;
   list<Logrec>::iterator itout=logouts.begin();
   while(itout!=logouts.end())
   {
       itin=logins.begin();
       while(itin!=logins.end())
       {
           /*
           char outip[257];
           itout->get_log_ip(outip);
           string out(outip);
           char inip[257];
           itin->get_log_ip(inip);
           string in(inip);
           */
           if(itin->get_pid()==itout->get_pid())
           {
               printf("M1>>>");
               char logname[32];
               char logip[257];
               long logintime;
               long logouttime;
               long onlinetime;
               itout->get_log_name(logname);
               itout->get_log_ip(logip);
               logintime=itin->get_log_time();
               logouttime=itout->get_log_time();
               onlinetime=logouttime-logintime;
               MLogrec m(logname,logip,logintime,logouttime,onlinetime);
               logs.push_back(m);

               /*
               char sname[32];(logs.rbegin())->get_log_name(sname);
               char sip[257];(logs.rbegin())->get_ip(sip);
               printf("%ld,%s,%s",(logs.rbegin())->get_online_time(),sip,sname);
               */

               logins.erase(itin);

               printf("<<<M2\n");
               break;
           }
           itin++;
       }
        printf("M3>>>>>>>>>>>\n");
       itout=logouts.erase(itout);
   }
   //logouts.clear();//没有登录记录匹配，丢弃登出记录
}

void LogReader::saveLogins()// throw(Logical View::IOException)
{
    char name[32];
    char ip[257];
    long time;
    pid_t pid;

    int fd=open(loginfile,O_WRONLY|O_TRUNC);
    //if(fd==-1)
       //fd=open(loginfile,O_CREAT|O_EXCL);
    list<Logrec>::iterator it=logins.begin();
    while(it!=logins.end())
    {
       it->get_log_name(name);
       write(fd,name,sizeof(name));
       it->get_log_ip(ip);
       write(fd,ip,sizeof(ip));
       time=it->get_log_time();
       write(fd,&time,sizeof(time));
       pid=it->get_pid();
       write(fd,&pid,sizeof(pid));
       it++;
    }
    logins.clear();
    close(fd);
}

void LogReader::readLogins() //throw(Logical View::IOException)
{
   char name[32];
   char ip[257];
   long time;
   pid_t pid;

   int fd=open(loginfile,O_RDONLY);
   if(fd==-1)
   {
       int fdc=open(loginfile,O_CREAT|O_EXCL);
       //if(fdc==-1)
       close(fdc);
       return;
   }
   struct stat st;
   int r=stat(loginfile,&st);
   int len=st.st_size/301;
   if(len==0) return;//len为0，则所有都有匹配

   int i;
   for(i=0;i<len;i++)
  {
     lseek(fd,i*301,SEEK_SET);
     read(fd,name,sizeof(name));
     lseek(fd,i*301+32,SEEK_SET);
     read(fd,ip,sizeof(ip));
     lseek(fd,i*301+289,SEEK_SET);
     read(fd,&time,sizeof(time));
     lseek(fd,i*301+297,SEEK_SET);
     read(fd,&pid,sizeof(pid));
     Logrec l(name,ip,time,pid);
     logins.push_back(l);
  }
   close(fd);
}

