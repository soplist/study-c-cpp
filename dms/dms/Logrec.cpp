#include "Logrec.h"

Logrec::Logrec(const char *logname,const char *logip,long logtime,pid_t pid):
        log_time(logtime),pid(pid)
{
     sprintf(log_name,"%s",logname);
     sprintf(log_ip,"%s",logip);
}

void Logrec::get_log_name(char name[])
{
    sprintf(name,"%s",log_name);
}
void Logrec::get_log_ip(char ip[])
{
    sprintf(ip,"%s",log_ip);
}
long Logrec::get_log_time()
{
    return log_time;
}
pid_t Logrec::get_pid()
{
    return pid;
}
