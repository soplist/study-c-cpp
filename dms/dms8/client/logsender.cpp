#include "logsender.h"  
#include <sys/types.h>
#include <sys/socket.h>    
#include <arpa/inet.h>  
#include <stdio.h>
#include <iostream>
using namespace std;
LogSender::LogSender(){
    sprintf(failSendFileName,"sendfail.dat");
    port=8899;
    sprintf(serverIp,"127.0.0.1");
}
        
LogSender::~LogSender(){ }
/*这个函数以后会被循环调用*/
bool  LogSender::sendMatche(MatchedLogRec mlog){
    int  sfd=send(fd,&mlog,sizeof mlog,0);
    if(sfd<=0){
       return false;
    }
    return true; 
}        
void LogSender::sendMatches(list<MatchedLogRec>* matches){
    readSendFailed(matches);
    initNetWork();
    /*循环发送数据 发送一条删除一条*/
    while(matches->size()>0){
        send(fd,&(*(matches->begin())),
        sizeof (MatchedLogRec),0);
        matches->erase(matches->begin());
    }
    saveSendFailed(matches);
}
        
void LogSender::initNetWork(){
    fd=socket(PF_INET,SOCK_STREAM,0);
    if(fd==-1){
        cout<<"init network failed"<<endl;  
    } 
    struct  sockaddr_in addr={0};
    addr.sin_family=PF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=inet_addr(serverIp);
    int  cfd=connect(fd,(sockaddr*)&addr,
          sizeof addr);
    if(cfd==-1){
         cout<<"connect server failed"<<endl;
    }   
}
        
void LogSender::readSendFailed(list<MatchedLogRec> *matches){}
        
void LogSender::saveSendFailed(list<MatchedLogRec> *matches){
    close(fd);
}


