#ifndef  DMSCLIENT_H
#define  DMSCLIENT_H
#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>
#include <QObject>
    class  DmsClient:public QDialog{
        Q_OBJECT
        private:
        QTextBrowser *data;
        QPushButton  *start;
        QPushButton  *close;
        public:
        DmsClient();
        ~DmsClient();
        /*完成数据的发送和显示*/
        public slots:
        void   startClient();  
    };
#endif
 
