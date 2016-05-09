#include "dmsclient.h"        
#include <pthread.h>
DmsClient::DmsClient(){
    this->resize(500,600);
    data=new QTextBrowser(this);
    start=new QPushButton("start",this);
    close=new QPushButton("close",this);
    data->resize(460,460);
    data->move(20,20);
    start->move(150,540);
    close->move(300,540);
    /*����start �� startClient*/
    myth=new MyThread();
    /*�����̵߳��źźͽ���Ĳ�*/
    connect(myth,SIGNAL(mySig(QString)),
            this,SLOT(setData(QString)));
    connect(start,SIGNAL(clicked()),
            this,SLOT(startClient()));
    connect(close,SIGNAL(clicked()),
            this,SLOT(close()));
}
DmsClient::~DmsClient(){
    delete  data;
    delete  start;
    delete  close;
}
/*�������ݵ��̺߳���*/
void *  processData(void *par){
    QTextBrowser *data=(QTextBrowser*)par;
    sleep(5);
    data->append("send data to server");
    sleep(5);
    data->append("client stop");
    return par;    
}
/*������ݵķ��ͺ���ʾ*/
void   DmsClient::startClient(){
    /*��ʱ�Ĳ���Ӧ�ý���˭?*/
    data->append("client start");
    /*�����߳�*/
    myth->start();
}
void   DmsClient::setData(QString par){
    data->append(par);   
} 

