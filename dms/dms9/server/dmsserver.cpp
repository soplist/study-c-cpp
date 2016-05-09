#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "data.h"
#include <deque>
#include "userdata.h"
#include "logdao.h"
using namespace std;
/*ȫ���� ��һ�����ݻ����*/
//deque<MatchedLogRec>  datapool;
UserData    datapool;
/*��װһ���߳��� ��ɽ������ݵĹ���
  ���������ݻ���ط������ݾ� 
*/
class  ProducterThread{
    private:
    pthread_t   thid;
    int         afd;
    public:
    static void  *reciveData(void *par){
        /*ϣ������run ͨ�������߳�ʱ��this*/
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
        /*��������������*/
        datapool.push_back(mlog);
    }
    close(afd);
   }
    ProducterThread(int afd){
        this->afd=afd;
    }
    public:
    /*�����߳�ʱ����ͻ���������*/
    void start(){ 
        pthread_create(&thid,0,reciveData,
        this);
    }
};
/*дһ���������߳� ��������ݳ���ȡ������*/
class  CustomerThread{
    private:
    pthread_t  thid;
    /*��������ݳ���ȡ������*/
    public: 
    static  void* customerData(void *par){
        LogDao   logdao;
        logdao.connect("openlab/open123");
        while(1){
            MatchedLogRec mlog=
            datapool.front();
            /*���÷������ݿ�Ķ���*/
            logdao.saveData(mlog); 
            logdao.commit();
        }
        logdao.disConnect();
    }
    public:
    void  start(){
        pthread_create(&thid,0,
        customerData,NULL);
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
    CustomerThread  customer;
    customer.start();
    while(1){
    struct sockaddr_in caddr={0};
    /*��������������*/
    socklen_t  clen=sizeof caddr; 
    int afd=accept(fd,(sockaddr*)&caddr,
    &clen);
    if(afd==-1){
        cout<<"accept client failed"<<endl;
    }
    /*��ȷ�Ͽͻ��˺� �����񽻸��߳�*/
    //pthread_t  thid;
   // pthread_create(&thid,0,reciveData,&afd);
     /*�����̶߳��� ��������*/
    /* ProducterThread  *producter=
     new ProducterThread(afd);
     producter->start();  */
     ProducterThread   producter(afd);
     producter.start();
    }
	 close(fd); 
}

