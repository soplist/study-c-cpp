#include "MLogrec.h"

MLogrec::MLogrec(const char *logname,const char *ip,
                 long logintime,long logouttime,long onlinetime)
    :m_login_time(logintime),m_logout_time(logouttime),m_online_time(onlinetime)
{
    sprintf(m_log_name,"%s",logname);
    sprintf(m_ip,"%s",ip);
}

void MLogrec::get_log_name(char name[])
{
    sprintf(name,"%s",m_log_name);
}

void MLogrec::get_ip(char ip[])
{
    sprintf(ip,"%s",m_ip);
}
long MLogrec::get_login_time()
{
    return m_login_time;
}
long MLogrec::get_logout_time()
{
    return m_logout_time;
}
long MLogrec::get_online_time()
{
    return m_online_time;
}
