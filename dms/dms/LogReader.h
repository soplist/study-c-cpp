#ifndef LOGREADER_H
#define LOGREADER_H

#include <list>
#include <cstdio>
#include <ctime>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "Logrec.h"
#include "MLogrec.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class LogReader
{
  public:
    LogReader(const char *lfile=NULL,const char *bfile=NULL,const char *linfile=NULL);

    void logRead();// throw(Logical View::LogReadException);

    list<MLogrec> logs;//已匹配记录链表

  private:
    void backupLog();//throw(Logical View::BackException);

    void readLog();// throw(Logical View::ReadException);

    void matchLog();

    void saveLogins();// throw(Logical View::IOException);

    void readLogins();// throw(Logical View::IOException);

    char logfile[50];//日志文件



    char backfile[50];//备份日志文件

    list<Logrec> logins;//登录记录链表

    list<Logrec> logouts;//登出记录链表

    char loginfile[50];//未匹配文件

};


#endif /* LOGREADER_H */
