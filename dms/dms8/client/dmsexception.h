#ifndef DMSEXCEPTION_H
#define DMSEXCEPTION_H
#include <exception>
#include <stdio.h>
using namespace std;
    class DmsException:public  exception{
        private:
        char   msg[200]; 
        public:
        DmsException(){
            sprintf(msg,"dms exception");
        }
        DmsException(const char *msg){
            sprintf(this->msg,msg);
        }
        const  char * what()const throw(){
            return  msg;   
        }
    };
    class  DmsClientException:
    public  DmsException{
         public:
         DmsClientException():
         DmsException("dms client exception"){

         }
         DmsClientException(const char*msg):
         DmsException(msg){

         }  
    };
    class DmsMatchException:
    public DmsClientException{
        public:
        DmsMatchException():
        DmsClientException("dms match log exception"){
        } 
        DmsMatchException(const char*msg):
        DmsClientException(msg){
        } 
    };
#endif
