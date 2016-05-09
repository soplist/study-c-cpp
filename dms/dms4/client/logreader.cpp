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
         /*��˳�����5�����ܺ���*/
         
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
    /*Ҫ�󱸷��ļ�����ѭ�����ʽ yyyymmddhhmiss
     20121222222222wtmpx   %02d*/
    sprintf(backFileName,"wtmpx");
    
}
         
void LogReader:: readFailLogins(){
    cout<<"2.read fail logins file"<<endl;
}
         
void LogReader:: readBackupFile(){
    cout<<"3.read backup log file"<<endl;
    /*��ȡ���ݺõ���־�ļ�  �Ѷ�ȡ������
      ����־�ļ��е����ݶ�ȡ���� 
      ��װ��LogRec���� 
      ���û����ǵ㿪ͷ�Ĺ��˵�
      ��logtype ��7�ķ���logins
      ��logtype ��8�ķ���logouts
      ��־�ļ�����unix�����ɵ�*/
    /*�ȵõ��ļ���С*/
      int  fd=open(backFileName,O_RDONLY);
      if(fd==-1){
          cout<<"open  log file failed"<<endl;
      } 
      struct   stat  flog={0};
      fstat(fd,&flog);
      cout<<flog.st_size<<endl;
      int  count=flog.st_size/372;
      LogRec   log;
      /*ѭ����ȡ�ļ��е�����  ������
      ���յ�¼���ͷ��벻ͬ�ļ���*/
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
          /*�ѵ㿪ͷ�����ֹ��˵�*/
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
     1.�ӵǳ�������ѭ��ȡ��һ���ǳ���¼
     2.�ڵ��뼯����ѭ������
     3.�ҵ�ƥ���¼
       �͹���ƥ���¼
       ����ƥ�伯��
       ɾ�������¼  �жϱ���ѭ��
     4.�������û�ҵ� �������� ֱ�����ҽ���
     5.��յǳ�����   */
    list<LogRec>::iterator  oit;
    list<LogRec>::iterator  iit;
    /*ʹ�õ�����ѭ���ӵǳ�������ȡ������*/
    for(oit=logouts.begin();oit!=logouts.end();oit++){
        /*ѭ���Ĵӵ��뼯���в���*/
        iit=logins.begin();
        while(iit!=logins.end()){
            if(!strcmp(iit->logname,oit->logname)
               && iit->pid == oit->pid &&
               !strcmp(iit->logip,oit->logip)){
                 MatchedLogRec   mlog;
                 /*��ֵ*/
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
      
