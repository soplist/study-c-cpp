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
        /*������ݵķ��ͺ���ʾ*/
        public slots:
        void   startClient();  
    };
#endif
 
