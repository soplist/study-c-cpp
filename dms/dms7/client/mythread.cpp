         /*��ɷ������� �������ź�*/
#include "mythread.h"         
#include "logreader.h"
#include "logsender.h"
void MyThread::run(){
    LogReader logreader;
    LogSender logsender;
    list<MatchedLogRec> matches=
    logreader.readLogs();
    /*׼����������*/
    logsender.initNetWork();
    char datastr[100]={0};
    /*ѭ����������*/
    while(matches.size()>0){
       sleep(1);
       bool f=logsender.sendMatche(*matches.begin());
      if(f){
          /*�����ź�*/
          sprintf(datastr,"%s:%d:%s",matches.begin()->logname,
          matches.begin()->pid,matches.begin()->logip);
          emit  mySig(QString(datastr));
          /*ɾ����������*/
          matches.erase(matches.begin());
      }else{
          break;
      }
    }
    /*�ر�fd*/
    logsender.saveSendFailed(&matches);
}

