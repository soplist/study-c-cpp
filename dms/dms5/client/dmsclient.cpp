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
    /*����start �� startClient*/
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
/*������ݵķ��ͺ���ʾ*/
void   DmsClient::startClient(){
    /*��ʱ�Ĳ���Ӧ�ý���˭?*/
    data->append("client start");
    sleep(10);
    data->append("send data to server");
    sleep(10);
    data->append("client stop");
}
 
