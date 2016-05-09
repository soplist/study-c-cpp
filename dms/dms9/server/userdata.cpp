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
/*�ṩ�̰߳�ȫ�ķ��ʺ���*/
/*�������ݵĺ���*/
         
void   UserData::push_back(MatchedLogRec mlog)
{
    pthread_mutex_lock(&mutext);
        while(datas.size()>1024*100){
            /*�ȴ�����������Ϊ��*/
            pthread_cond_wait(&pcon,&mutext); 
        }
        datas.push_back(mlog);
        //֪ͨ������
        pthread_cond_signal(&ccon);
    pthread_mutex_unlock(&mutext); 
}
/*�õ����ݲ�ɾ���ĺ���*/
MatchedLogRec UserData::front(){
    pthread_mutex_lock(&mutext);
        while(datas.empty()){
            /*�ȴ����ѵ�����Ϊ��*/  
            pthread_cond_wait(&ccon,&mutext); 
        }
        MatchedLogRec mlog=datas.front();
        datas.pop_front();
        //���ٿ�������һ�� ����֪ͨ����
        pthread_cond_broadcast(&pcon);
    pthread_mutex_unlock(&mutext); 
    return  mlog;    
}

