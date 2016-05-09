#ifndef  MYTHREAD_H
#define  MYTHREAD_H
#include <QThread>
#include <QString>
     /*这是一个自定义的线程类*/
     class  MyThread:public QThread{
         Q_OBJECT
         /*完成发送数据 并发射信号*/
         public:
         void run();
         /*定义一个通知界面 发送了那些数据的
         信号*/
         public:signals:
         void   mySig(QString data);
     };
#endif
