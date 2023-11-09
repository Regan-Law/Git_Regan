// winserver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <winsock2.h>
#include <thread>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

#define TCP_PORT  6060
#define MAX_PACKET_LEN  1024
int currentClient = 0; //当前客户端数量
void handle_client(SOCKET sClient, char*__stdcall ip, u_short port) {
    char recvData[MAX_PACKET_LEN + 1];
    int ret;

    while (1) {
        ret = recv(sClient, recvData, MAX_PACKET_LEN, 0);
        if (ret > 0)
        {
            recvData[ret] = '\0';
            printf("从客户端[IP地址：%s，端口号：%d]接收消息: %s\n",ip,port, recvData);
            if (strcmp(recvData, "EXIT") == 0) {
                currentClient--;
                printf("客户端[IP地址：%s，端口号：%d]断开连接\n",ip,port);
                break;
            }
        }
        char sendData[MAX_PACKET_LEN + 1];
        memset(sendData, 0, MAX_PACKET_LEN + 1);
        sprintf_s(sendData, "[来自服务器端] 消息已被接收! \n欢迎 IP地址：%s，端口号：%d\n",ip,port);
        ret = send(sClient, sendData, strlen(sendData), 0);
        if (ret == SOCKET_ERROR)
        {
            printf("send error !");
        }

    }
    closesocket(sClient);
}

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
        currentClient++;
        printf("客户端连接成功，IP地址：%s，端口号：%d\n你是第%d个连接的客户端,当前客户端数量:%d\n", inet_ntoa(remoteAddr.sin_addr), ntohs(remoteAddr.sin_port),nCounter,currentClient);

        // 创建一个新的线程来处理这个客户端连接
        std::thread client_thread(handle_client, sClient, inet_ntoa(remoteAddr.sin_addr), ntohs(remoteAddr.sin_port));
        client_thread.detach();  // 分离线程，让它自行运行
    }

    closesocket(slisten);
    WSACleanup();   //解除应用程序和winsock.dll库的绑定
    return 0;
}