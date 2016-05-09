#include "userdata.h"         
UserData::UserData(){
    pthread_mutex_init(&mutext,0);
    pthread_cond_init(&pcon,0);
    pthread_cond_init(&ccon,0);
}
UserData::~UserData(){
    pthread_mutex_destroy(&mutext);
    pthread_cond_destroy(&pcon);
    pthread_cond_destroy(&ccon);
}
/*提供线程安全的访问函数*/
/*存入数据的函数*/
         
void   UserData::push_back(MatchedLogRec mlog)
{
    pthread_mutex_lock(&mutext);
        while(datas.size()>1024*100){
            /*等待生产的条件为真*/
            pthread_cond_wait(&pcon,&mutext); 
        }
        datas.push_back(mlog);
        //通知消费者
        pthread_cond_signal(&ccon);
    pthread_mutex_unlock(&mutext); 
}
/*得到数据并删除的函数*/
MatchedLogRec UserData::front(){
    pthread_mutex_lock(&mutext);
        while(datas.empty()){
            /*等待消费的条件为真*/  
            pthread_cond_wait(&ccon,&mutext); 
        }
        MatchedLogRec mlog=datas.front();
        datas.pop_front();
        //至少可以生产一条 可以通知生产
        pthread_cond_broadcast(&pcon);
    pthread_mutex_unlock(&mutext); 
    return  mlog;    
}

