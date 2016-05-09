#ifndef LOGSENDER_H
#define LOGSENDER_H

#include "ILogSend.h"
#include "MLogrec.h"
#include <cstring>
#include <list>
#include <cstdio>
#include <sys/socket.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

class LogSender:public ILogSend
{
  public:

    LogSender(const char *ip=NULL,int port=0,const char *file=NULL,bool linked=false);

    void logSend();

    list<MLogrec>* logs;//匹配记录

   private:

    void saveFailure(); //throw(Logical View::IOException);

    void linkServer(); //throw(Logical View::LinkException);

    void readLastFailure();// throw(Logical View::IOException);

    void sendLog(); //throw(Logical View::SendException);

    int fds;

    bool linked;

    char ip[30];

    short port;

    char failfile[50];//发送失败文件

};

#endif /* LOGSENDER_H */
