// socketserver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <WINSOCK2.H>
#pragma comment(lib,"ws2_32.lib")
void TCPServer()
{
   //���������׽���
	SOCKET sockSvr=socket(AF_INET,
		SOCK_STREAM,IPPROTO_TCP);
	if (sockSvr==INVALID_SOCKET)//����ʧ��
	{
		return;
	}
	//�󶨵�ַ�Ͷ˿�
	SOCKADDR_IN svrAddr={0};
	svrAddr.sin_family=AF_INET;
	svrAddr.sin_port=htons(5678);
	svrAddr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(sockSvr,(SOCKADDR*)&svrAddr,sizeof(svrAddr));
	//����
	listen(sockSvr,5);
	//�Ⱥ�����
	printf("�Ⱥ�ͻ�������...\n");
    SOCKADDR_IN clientAddr={0};
    int nLen=sizeof(clientAddr);
	SOCKET sockClient=accept(sockSvr,
		(SOCKADDR*)&clientAddr,&nLen);
	printf("�ͻ���������.\n");
	//�����շ�
	char szText[100]={0};
	recv(sockClient,szText,100,0);
	printf("�ͻ�������:%s\n",szText);
	char szSend[100]="Hello TCP Client";
	send(sockClient,szSend,100,0);
	//�ر�socket
	closesocket(sockClient);
	closesocket(sockSvr);


}
int main(int argc, char* argv[])
{
	//��ʼ��socket
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
    TCPServer();
	return 0;
}

