         /*完成发送数据 并发射信号*/
#include "mythread.h"         
void MyThread::run(){
    sleep(5);
    emit mySig("send data to server");
    sleep(1);
    emit mySig("send data to server");
    sleep(1);
    emit mySig("send data to server");
    sleep(1);
    emit mySig("send data to server");
    sleep(1);
    emit mySig("send over!");
}

