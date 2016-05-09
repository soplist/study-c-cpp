#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
/*构建一个高速访问文件的场景
测试数据的备份是否连续*/
int main(){
    double  data=1.0;
    char    datastr[50]={0};
    for(;;){
        int fd=open("wtmpx.dat",O_RDWR|O_CREAT|O_EXCL|O_APPEND,0777);
        if(fd==-1){
            fd=open("wtmpx.dat",O_RDWR|O_APPEND);  
        }
        sprintf(datastr,"%lf\n",data);
        write(fd,datastr,strlen(datastr));
        data=data+1.0;
        close(fd);
    }
}

