#ifndef DMSCLIENT_H
#define DMSCLIENT_H
#include "LogReader.h"
#include "ILogSend.h"
#include "LogSender.h"

class DMSClient
{
  public:
    void dms();

    LogReader* reader;
    LogSender* sender;
};

#endif /*  DMSCLIENT_H */
