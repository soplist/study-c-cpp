#include "DMSClient.h"


void DMSClient::dms()
{
   int i=0;
   for(i;i<3;i++)
    {
       reader->logRead();

       sender->logs=&(reader->logs);

       sender->logSend();
       sleep(3);
    }
}

