#include "LogReader.h"
#include "LogSender.h"
#include "DMSClient.h"
int main()
{
        LogReader reader("/home/soft01/uc/f/wtmpx","/home/soft01/uc/f/b","/home/soft01/uc/f/in");
        LogSender sender("192.168.244.134",9999,"/home/soft01/uc/f/fail");
        DMSClient client;
	client.reader=&reader;
        client.sender=&sender;
        client.dms();
        /*
	try{
		client.dms();
	}
        catch(DMSClientException e){
		
	}
         */
}
