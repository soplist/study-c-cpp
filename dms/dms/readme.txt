Author:Antonio
环境：Linux
开发工具：g++ make

在命令行 make 生成 server为采集端
在命令行 make recvser 生成 recvser为模拟接收端

make clean 清除采集端生成的文件
make clean 清除模拟端生成的文件

/***演示时先开 recvser 能看到效果，recvser有阻塞函数，不开server端，recvser会阻塞而不能自行结束***/


