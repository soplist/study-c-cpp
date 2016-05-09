#include "logreader.h"
#include "logsender.h"
int main(){
    LogReader  logreader;
    LogSender  logsender;
    list<MatchedLogRec>  matches=
    logreader.readLogs();
    logsender.sendMatches(&matches);
}


