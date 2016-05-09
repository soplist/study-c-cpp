#ifndef  USERDATA_H
#define  USERDATA_H
#include "data.h"
#include <pthread.h>
#include <deque>
using namespace std;
     /*这个类的函数是线程安全的 
      类的函数之间可以通信 可以完成 
      生产者消费者模型的需求*/
     class  UserData{
         private:
         /*数据池真正存数据的*/
         deque<MatchedLogRec> datas;
         /*保证线程安全的锁*/
         pthread_mutex_t      mutext;
         /*为了保证生产和消费的协调的条件量*/
         pthread_cond_t       pcon;
         pthread_cond_t       ccon;
         public:
         UserData();
         ~UserData(); 
         /*提供线程安全的访问函数*/
         /*存入数据的函数*/
         void   push_back(MatchedLogRec mlog);
         /*得到数据并删除的函数*/
         MatchedLogRec front();
     }; 
#endif
