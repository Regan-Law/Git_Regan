// winserver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

#define TCP_PORT  6060
#define MAX_PACKET_LEN  1024

int main(int argc, char* argv[])
{
    int ret = 0;

    //初始化WSA
    WORD sockVersion = MAKEWORD(2, 2);  //使用WinSock2.2版本
    WSADATA wsaData;
    ret = WSAStartup(sockVersion, &wsaData);
    if (ret != 0) //如果找不到合适的winsock.dll文件，返回。
    {
        printf("WSAStartup error !");
        return 1;
    }

    //创建套接字
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (slisten == INVALID_SOCKET)
    {
        printf("Invalid socket !");
        WSACleanup();
        return 1;
    }

    //绑定IP和端口
    sockaddr_in sin;    //(1)定义sockaddr_in变量
    sin.sin_family = AF_INET;  //（2）为该socket变量个成员赋值
    sin.sin_port = htons(TCP_PORT);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;  // 设置本地IP地址

    //(3)调用socket API时强制类型转换sockaddr
    ret = bind(slisten, (sockaddr*)&sin, sizeof(sockaddr_in));
    if (ret == SOCKET_ERROR)
    {
        printf("bind error !");
        closesocket(slisten);
        WSACleanup();
        return 1;
    }

    //开始监听，并制定监听套接字请求队列长度
    if (listen(slisten, 5) == SOCKET_ERROR)
    {
        printf("listen error !");
        closesocket(slisten);
        WSACleanup();
        return 1;
    }

    printf("This is TCP Server, waiting for connecting......\n");

    //循环接收数据，服务器主循环接收和处理来自客户端的连接请求
    SOCKET sClient;
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);
    char recvData[MAX_PACKET_LEN + 1];
    int nCounter = 0; //客户端连接计数器
    while (1)
    {
        sClient = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);
        if (sClient == INVALID_SOCKET)
        {
            printf("accept error !");
            continue;
        }

        nCounter++;

        // inet_ntoa:修改VS配置，告诉它我就要旧函数，修改方法：项目->属性->C / C++->常规->SDL检查，将“是”改为“否”，即可。
        // 该处增加代码，实现实验要求以下功能：
        //(3)显示请求的地址信息，包括客户端IP地址和端口号。
       printf("客户端连接成功，IP地址：%s，端口号：%d\n", inet_ntoa(remoteAddr.sin_addr), ntohs(remoteAddr.sin_port));

        //接收数据
        ret = recv(sClient, recvData, MAX_PACKET_LEN, 0);
        if (ret > 0)
        {
            recvData[ret] = '\0';
            printf("Received data from client: %s\n", recvData);
        }

        //发送数据    
        char sendData[MAX_PACKET_LEN + 1];
        memset(sendData, 0, MAX_PACKET_LEN + 1);

        sprintf_s(sendData, "[From TCP Server] Hello, TCP server has been connected %d times! ", nCounter);
        ret = send(sClient, sendData, strlen(sendData), 0);
        if (ret == SOCKET_ERROR)
        {
            printf("send error !");
        }

        // 该处增加代码，实现实验要求以下功能：
        // （4）服务器端程序循环接收客户端报文，并输出到屏幕；
        // （5）如果报文为"EXIT" ，则停止接收。

        while (1) {
            ret = recv(sClient, recvData, MAX_PACKET_LEN, 0);
            if (ret > 0)
            {
                recvData[ret] = '\0';
                printf("Received data from client: %s\n", recvData);
                if (strcmp(recvData, "EXIT") == 0) {
                    printf("Receive stopped !\n");
                    break;
                }
            }
            memset(sendData, 0, MAX_PACKET_LEN + 1);
            sprintf_s(sendData, "[From TCP Server] Message has been received! ");
            ret = send(sClient, sendData, strlen(sendData), 0);
            if (ret == SOCKET_ERROR)
            {
                printf("send error !");
            }
        }
        closesocket(sClient);
    }

    closesocket(slisten);
    WSACleanup();   //解除应用程序和winsock.dll库的绑定
    return 0;
}