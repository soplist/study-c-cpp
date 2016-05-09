#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "data.h"
using namespace std;

int main(){
    int fd=socket(PF_INET,SOCK_STREAM,0);
    if(fd==-1){
        cout<<"init socket failed"<<endl;
    }
    struct sockaddr_in addr={0};
    addr.sin_family=PF_INET;
    addr.sin_port=htons(8899);
    addr.sin_addr.s_addr=INADDR_ANY;
    int  bfd=bind(fd,(sockaddr*)&addr,
    sizeof addr);
    if(bfd==-1){
        cout<<"bind failed"<<endl;
    }
    listen(fd,10);
    struct sockaddr_in caddr={0};
    /*程序明天有问题*/
    socklen_t  clen; 
    int afd=accept(fd,(sockaddr*)&caddr,
    &clen);
    if(afd==-1){
        cout<<"accept client failed"<<endl;
    }
    MatchedLogRec   mlog={0};
    while(1){
        int  rfd=recv(afd,&mlog,
                 sizeof mlog,0);
        if(rfd<=0){
            break;
        }
        cout<<mlog.logname<<":"<<
        mlog.logip<<endl;  
    }
    close(afd);
	 close(fd); 
}

