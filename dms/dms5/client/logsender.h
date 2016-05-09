#ifndef  LOGSENDER_H
#define  LOGSENDER_H
#include "data.h"
#include <list>
using namespace std;
    class LogSender{
        private:
        char failSendFileName[50];
        int  fd;
        unsigned short port;
        char serverIp[20];
        public:
        LogSender();
        ~LogSender();
        void  sendMatches(list<MatchedLogRec>* matches);
        void  initNetWork();
        void  readSendFailed(list<MatchedLogRec> *matches);
        void  saveSendFailed(list<MatchedLogRec> *matches);
    }; 
#endif
