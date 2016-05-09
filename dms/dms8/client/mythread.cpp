         /*完成发送数据 并发射信号*/
#include "mythread.h"         
#include "logreader.h"
#include "logsender.h"
void MyThread::run(){
    LogReader logreader;
    LogSender logsender;
    list<MatchedLogRec> matches=
    logreader.readLogs();
    /*准备发送数据*/
    logsender.initNetWork();
    char datastr[100]={0};
    /*循环发送数据*/
    while(matches.size()>0){
       sleep(1);
       bool f=logsender.sendMatche(*matches.begin());
      if(f){
          /*发射信号*/
          sprintf(datastr,"%s:%d:%s",matches.begin()->logname,
          matches.begin()->pid,matches.begin()->logip);
          emit  mySig(QString(datastr));
          /*删除这条数据*/
          matches.erase(matches.begin());
      }else{
          break;
      }
    }
    /*关闭fd*/
    logsender.saveSendFailed(&matches);
}

