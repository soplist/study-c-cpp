#ifndef  LOGREADER_H
#define  LOGREADER_H
#include "data.h"
#include <list>
using namespace std;
     class  LogReader{
         private:
         char  logFileName[50];
         char  backFileName[50];
         char  failLoginsFile[50];
         list<LogRec>  logins;
         list<LogRec>  logouts;
         list<MatchedLogRec> matches;
         public:
         LogReader();
         ~LogReader();
         /*��˳�����5�����ܺ���*/
         list<MatchedLogRec> readLogs();
         private:
         void  backup();
         void  readFailLogins();
         void  readBackupFile();
         void  matchLogRec(); 
         void  saveFailLogins();         
     };
#endif
