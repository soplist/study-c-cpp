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
    /*连接start 和 startClient*/
    myth=new MyThread();
    /*关联线程的信号和界面的槽*/
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
/*处理数据的线程函数*/
void *  processData(void *par){
    QTextBrowser *data=(QTextBrowser*)par;
    sleep(5);
    data->append("send data to server");
    sleep(5);
    data->append("client stop");
    return par;    
}
/*完成数据的发送和显示*/
void   DmsClient::startClient(){
    /*耗时的操作应该交给谁?*/
    data->append("client start");
    /*启动线程*/
    myth->start();
}
void   DmsClient::setData(QString par){
    data->append(par);   
} 

