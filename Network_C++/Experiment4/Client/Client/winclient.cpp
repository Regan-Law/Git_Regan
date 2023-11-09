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
	//WinScok初始化注册
	WORD sockVersion = MAKEWORD(2, 2);   //生成版本号2.2
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)  //如果找不到ws2_32.lib文件，直接返回
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

	// inet_addr:修改VS配置，修改方法：项目->属性->C / C++->常规->SDL检查，将“是”改为“否”。
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
	// sprintf(sendData, "[来自客户端] 这里是客户端!");
	while (1) 
	{
	printf("请输入报文信息：");
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
	//解除和DLL库的绑定
	WSACleanup();

	return 0;
}