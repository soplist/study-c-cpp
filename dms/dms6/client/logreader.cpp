#include "logreader.h"
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
using namespace std;         
LogReader::LogReader(){cout<<""<<endl;}
         
LogReader::~LogReader(){cout<<""<<endl;}
         /*按顺序调用5个功能函数*/
         
list<MatchedLogRec> LogReader::readLogs(){
    backup();
    readFailLogins();
    readBackupFile();
    cout<<"logins:"<<logins.size()<<endl;
    cout<<"logouts:"<<logouts.size()<<endl;
    matchLogRec();
    cout<<"matches:"<<matches.size()<<endl;
    cout<<"logins:"<<logins.size()<<endl;
    cout<<"logouts:"<<logouts.size()<<endl;
    saveFailLogins();
    return matches;
}
         
void LogReader:: backup(){
    cout<<"1.back up log file"<<endl;
    /*要求备份文件名遵循这个格式 yyyymmddhhmiss
     20121222222222wtmpx   %02d*/
    sprintf(backFileName,"wtmpx");
    
}
         
void LogReader:: readFailLogins(){
    cout<<"2.read fail logins file"<<endl;
}
         
void LogReader:: readBackupFile(){
    cout<<"3.read backup log file"<<endl;
    /*读取备份好的日志文件  把读取的数据
      把日志文件中的数据读取出来 
      封装成LogRec对象 
      把用户名是点开头的过滤掉
      把logtype 是7的放入logins
      把logtype 是8的放入logouts
      日志文件是在unix下生成的*/
    /*先得到文件大小*/
      int  fd=open(backFileName,O_RDONLY);
      if(fd==-1){
          cout<<"open  log file failed"<<endl;
      } 
      struct   stat  flog={0};
      fstat(fd,&flog);
      cout<<flog.st_size<<endl;
      int  count=flog.st_size/372;
      LogRec   log;
      /*循环读取文件中的数据  把数据
      按照登录类型放入不同的集合*/
      for(int i=0;i<count;i++){
          read(fd,&log.logname,32);
          lseek(fd,36,SEEK_CUR);
          read(fd,&log.pid,4);
          log.pid=htonl(log.pid);  
          read(fd,&log.logtype,2);
          log.logtype=htons(log.logtype);
          lseek(fd,6,SEEK_CUR);
          read(fd,&log.logtime,4);
          log.logtime=htonl(log.logtime);
          lseek(fd,30,SEEK_CUR);
          read(fd,&log.logip,257);
          lseek(fd,1,SEEK_CUR);
          cout<<log.logname<<":"<<
          log.logtype<<endl;
          /*把点开头的名字过滤掉*/
          if(log.logname[0]!='.'){
              if(log.logtype==7){
                  logins.push_back(log); 
              }else if(log.logtype==8){
                  logouts.push_back(log);
              }else{
                 ;   
              }
          }           
      }
      close(fd);
}
         
void LogReader:: matchLogRec(){
    cout<<"4.match log rec"<<endl;
    /*
     1.从登出集合中循环取出一条登出记录
     2.在登入集合中循环查找
     3.找到匹配记录
       就构造匹配记录
       加入匹配集合
       删除登入记录  中断本次循环
     4.如果本次没找到 继续查找 直到查找结束
     5.清空登出集合   */
    list<LogRec>::iterator  oit;
    list<LogRec>::iterator  iit;
    /*使用迭代器循环从登出集合中取出数据*/
    for(oit=logouts.begin();oit!=logouts.end();oit++){
        /*循环的从登入集合中查找*/
        iit=logins.begin();
        while(iit!=logins.end()){
            if(!strcmp(iit->logname,oit->logname)
               && iit->pid == oit->pid &&
               !strcmp(iit->logip,oit->logip)){
                 MatchedLogRec   mlog;
                 /*赋值*/
                 sprintf(mlog.logname,iit->logname);
                 mlog.pid=iit->pid;
                 mlog.logintime=iit->logtime;
                 mlog.logouttime=oit->logtime;
                 mlog.durations=mlog.logouttime-
                      mlog.logintime;
                 sprintf(mlog.logip,iit->logip);  
                 matches.push_back(mlog);
                 logins.erase(iit);
                 break;           
            } 
            iit++; 
        }
    }
    logouts.clear();   
} 
         
void LogReader:: saveFailLogins(){
    cout<<"5.save fail logins"<<endl;
        
}   
      
