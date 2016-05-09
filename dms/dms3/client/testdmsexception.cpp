#include "dmsexception.h"
#include <iostream>
using namespace std;
int main(){
    DmsException  *parent=
    new DmsClientException("dms client back up exception");
    cout<<parent->what()<<endl;  
}

