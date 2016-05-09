#include "dmsclient.h"        
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
/*完成数据的发送和显示*/
void   DmsClient::startClient(){
    /*耗时的操作应该交给谁?*/
    data->append("client start");
    sleep(10);
    data->append("send data to server");
    sleep(10);
    data->append("client stop");
}
 
