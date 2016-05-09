#ifndef MLOGREC_H
#define MLOGREC_H
#include <cstdio>
class MLogrec
{
  char m_log_name[32];
  char m_ip[257];
  long m_login_time;
  long m_logout_time;
  long m_online_time;
public:
  MLogrec(const char *logname=NULL,const char *ip=NULL,
          long logintime=0,long logouttime=0,long onlinetime=0);
  /*
  MLogrec(const MLogrec &obj);
  MLogrec &operator=(const MLogrec &obj);
  */
  void get_log_name(char name[]);
  void get_ip(char ip[]);
  long get_login_time();
  long get_logout_time();
  long get_online_time();

};
#endif // MLOGREC_H
