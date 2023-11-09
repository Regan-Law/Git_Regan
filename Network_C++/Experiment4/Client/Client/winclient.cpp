// winclient.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <winsock2.h>
#include <thread>
#pragma  comment(lib,"ws2_32.lib")

#define TCP_PORT 6060
#define MAX_PACKET_LEN  1024

int main(int argc, char* argv[])
{
	int ret = 0;
	//WinScok��ʼ��ע��
	WORD sockVersion = MAKEWORD(2, 2);   //���ɰ汾��2.2
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)  //����Ҳ���ws2_32.lib�ļ���ֱ�ӷ���
	{
		printf("WSAStartup error !");
		return 1;
	}

	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{
		printf("Invalid socket !");
		WSACleanup();
		return 1;
	}

	printf("This is TCP Client! \n");

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(TCP_PORT);

	// inet_addr:�޸�VS���ã��޸ķ�������Ŀ->����->C / C++->����->SDL��飬�����ǡ���Ϊ���񡱡�
	serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 
	
	ret = connect(sclient, (sockaddr *)&serAddr, sizeof(sockaddr_in));
	if (ret == SOCKET_ERROR)
	{
		printf("Connect error !");
		closesocket(sclient);
		WSACleanup(); 
		return 1;
	}
	char sendData[MAX_PACKET_LEN+1];
	char recvData[MAX_PACKET_LEN+1];
	// memset(sendData, 0, MAX_PACKET_LEN+1);
	// sprintf(sendData, "[���Կͻ���] �����ǿͻ���!");
	while (1) 
	{
	printf("�����뱨����Ϣ��");
	fgets(sendData, MAX_PACKET_LEN, stdin);
	sendData[strlen(sendData) - 1] = '\0';

	ret = send(sclient, sendData, strlen(sendData), 0);
	if (SOCKET_ERROR == ret)
	{
		printf("send error !");
		break;
	}

	if (strcmp(sendData, "EXIT") == 0) {
		break;
	}

	ret = recv(sclient, recvData, MAX_PACKET_LEN, 0);
	if (ret > 0)
	{
		recvData[ret] = '\0';
		printf("%s \n", recvData);
	}
	}
	closesocket(sclient);
	//�����DLL��İ�
	WSACleanup();

	return 0;
}