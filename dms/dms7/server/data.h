#ifndef  DATA_H
#define  DATA_H
   /*����ǳ���¼*/
    struct LogRec{
        char  logname[32];
        int   pid;
        short logtype;
        int   logtime;
        char  logip[257];
    };
    /*ƥ���¼����*/
    struct MatchedLogRec{
        char  logname[32];
        int   pid;
        int   logintime;
        int   logouttime;
        int   durations;
        char  logip[257];
        /*ͳ��ÿ̨����������Ϣ*/
        char  labip[20];
    };
#endif

