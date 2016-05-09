#ifndef  DMSCLIENT_H
#define  DMSCLIENT_H
#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>
#include <QObject>
#include "mythread.h"
    class  DmsClient:public QDialog{
        Q_OBJECT
        private:
        QTextBrowser *data;
        QPushButton  *start;
        QPushButton  *close;
        /*操作界面的线程对象指针*/
        MyThread    *myth;
        /*提供一个接收线程信号的槽函数*/
        public slots:
        void   setData(QString par);        
        public:
        DmsClient();
        ~DmsClient();
        /*完成数据的发送和显示*/
        public slots:
        void   startClient();  
    };
#endif
 
