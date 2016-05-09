#ifndef  LOGDAO_H
#define  LOGDAO_H
#include "data.h"
     class  LogDao{
         public:
         void   connect(char *userpwd);
         void   saveData(MatchedLogRec mlog);
         void   commit();
         void   disConnect();    
     };
#endif
