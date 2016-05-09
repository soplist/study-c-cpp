#ifndef  USERDATA_H
#define  USERDATA_H
#include "data.h"
#include <pthread.h>
#include <deque>
using namespace std;
     /*�����ĺ������̰߳�ȫ�� 
      ��ĺ���֮�����ͨ�� ������� 
      ������������ģ�͵�����*/
     class  UserData{
         private:
         /*���ݳ����������ݵ�*/
         deque<MatchedLogRec> datas;
         /*��֤�̰߳�ȫ����*/
         pthread_mutex_t      mutext;
         /*Ϊ�˱�֤���������ѵ�Э����������*/
         pthread_cond_t       pcon;
         pthread_cond_t       ccon;
         public:
         UserData();
         ~UserData(); 
         /*�ṩ�̰߳�ȫ�ķ��ʺ���*/
         /*�������ݵĺ���*/
         void   push_back(MatchedLogRec mlog);
         /*�õ����ݲ�ɾ���ĺ���*/
         MatchedLogRec front();
     }; 
#endif
