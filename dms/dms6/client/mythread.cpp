         /*��ɷ������� �������ź�*/
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

