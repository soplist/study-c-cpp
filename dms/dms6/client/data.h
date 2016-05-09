#ifndef  DATA_H
#define  DATA_H
   /*登入登出记录*/
    struct LogRec{
        char  logname[32];
        int   pid;
        short logtype;
        int   logtime;
        char  logip[257];
    };
    /*匹配记录类型*/
    struct MatchedLogRec{
        char  logname[32];
        int   pid;
        int   logintime;
        int   logouttime;
        int   durations;
        char  logip[257];
        /*统计每台服务器的信息*/
        char  labip[20];
    };
#endif

