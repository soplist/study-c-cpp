#ifndef  MYTHREAD_H
#define  MYTHREAD_H
#include <QThread>
#include <QString>
     /*����һ���Զ�����߳���*/
     class  MyThread:public QThread{
         Q_OBJECT
         /*��ɷ������� �������ź�*/
         public:
         void run();
         /*����һ��֪ͨ���� ��������Щ���ݵ�
         �ź�*/
         public:signals:
         void   mySig(QString data);
     };
#endif
