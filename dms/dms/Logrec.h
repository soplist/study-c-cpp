#ifndef LOGREC_H
#define LOGREC_H
#include <ctime>
#include <unistd.h>
#include <cstdio>
class Logrec
{
    char log_name[32];
    char log_ip[257];
    long log_time;
    pid_t pid;
public:
    Logrec(const char *logname=NULL,const char *logip=NULL,long logtime=0,pid_t pid=0);

    void get_log_name(char name[]);
    void get_log_ip(char ip[]);
    long get_log_time();
    pid_t get_pid();

};
#endif // LOGREC_H
