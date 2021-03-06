#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "data.h"
using namespace std;
/*包装一个线程类 完成接收数据的功能
  负责向数据缓冲池放入数据据 
*/
class  ProducterThread{
    private:
    pthread_t   thid;
    int         afd;
    public:
    static void  *reciveData(void *par){
        /*希望调用run 通过创建线程时传this*/
        ((ProducterThread*)par)->run();
    }
    void  run(){
    int afd=this->afd;
    MatchedLogRec   mlog={0};
    while(1){
        int  rfd=recv(afd,&mlog,
                 sizeof mlog,0);
        if(rfd<=0){
            break;
        }
        cout<<afd<<":"<<mlog.logname<<":"<<
        mlog.logip<<endl;  
    }
    close(afd);
   }
    ProducterThread(int afd){
        this->afd=afd;
    }
    public:
    /*创建线程时传入客户端描述符*/
    void start(){ 
        pthread_create(&thid,0,reciveData,
        this);
    }
};
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
    while(1){
    struct sockaddr_in caddr={0};
    /*程序明天有问题*/
    socklen_t  clen=sizeof caddr; 
    int afd=accept(fd,(sockaddr*)&caddr,
    &clen);
    if(afd==-1){
        cout<<"accept client failed"<<endl;
    }
    /*当确认客户端后 把任务交给线程*/
    //pthread_t  thid;
   // pthread_create(&thid,0,reciveData,&afd);
     /*创建线程对象 接收数据*/
    /* ProducterThread  *producter=
     new ProducterThread(afd);
     producter->start();  */
     ProducterThread   producter(afd);
     producter.start();
    }
	 close(fd); 
}

