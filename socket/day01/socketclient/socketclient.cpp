// socketclient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WINSOCK2.H>
void TCPClient()
{
   //����socket
	SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
	if (sockClient==INVALID_SOCKET)//����ʧ��
	{
		return;
	}
	//���ӷ�����
	SOCKADDR_IN addrSvr={0};
	addrSvr.sin_family=AF_INET;
	addrSvr.sin_port=htons(5678);
	addrSvr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	connect(sockClient,(SOCKADDR*)&addrSvr,
		sizeof(addrSvr));
	//�վ��շ�
	CHAR szSend[100]="Hello TCP Server";
	send(sockClient,szSend,100,0);
	char szText[100]={0};
	recv(sockClient,szText,100,0);
	printf("������������:%s\n",szText);
	//�ر��׽���
	closesocket(sockClient);
}
int main(int argc, char* argv[])
{
	//��ʼ��socket��
	WSAData wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
    TCPClient();
	printf("Hello World!\n");
	return 0;
}

