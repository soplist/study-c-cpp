// socketserver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")
void TCPServer()
{
   //创建监听套接字
	SOCKET sockSvr=socket(AF_INET,
		SOCK_STREAM,IPPROTO_TCP);
	if (sockSvr==INVALID_SOCKET)//创建失败
	{
		return;
	}
	//绑定地址和端口
	SOCKADDR_IN svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5678);
	svrAddr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(sockSvr,(SOCKADDR*)&svrAddr,sizeof(svrAddr));
	//侦听
	listen(sockSvr,5);
	//等候连接
	printf("等候客户端连接...\n");
    SOCKADDR_IN clientAddr={0};
    int nLen=sizeof(clientAddr);
	SOCKET sockClient=accept(sockSvr,
		(SOCKADDR*)&clientAddr,&nLen);
	printf("客户端已连接.\n");
	//数据收发
	char szText[100]={0};
	recv(sockClient,szText,100,0);
	printf("客户端数据:%s\n",szText);
	char szSend[100]="Hello TCP Client";
	send(sockClient,szSend,100,0);
	//关闭socket
	closesocket(sockClient);
	closesocket(sockSvr);


}
int main(int argc, char* argv[])
{
	//初始化socket
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
    TCPServer();
	return 0;
}

