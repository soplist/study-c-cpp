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
        /*����������̶߳���ָ��*/
        MyThread    *myth;
        /*�ṩһ�������߳��źŵĲۺ���*/
        public slots:
        void   setData(QString par);        
        public:
        DmsClient();
        ~DmsClient();
        /*������ݵķ��ͺ���ʾ*/
        public slots:
        void   startClient();  
    };
#endif
 
