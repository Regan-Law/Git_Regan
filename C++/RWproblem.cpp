#include "windows.h"
#include<conio.h>
#include<tchar.h>
#include<stdlib.h>
#include<fstream>
#include<io.h>
#include<string.h>
#include<stdio.h>
#define READER 'R'// 读者
#define WRITER 'W'// 写者
#define INTE_PER_SEC 1000// 每秒时钟中断的数目
#define MAX_THREAD_NUM 64// 最大线程数
#define MAX_FILE_NUM 32// 最大文件数目数
#define MAX_STR_LEN 32// 字符串的长度
int readcount=0;// 读者数目
int writecount=0;// 写者数目
CRITICAL_SECTION RP_Write;// 临界资源
CRITICAL_SECTION cs_Write;
CRITICAL_SECTION cs_Read;
struct ThreadInfo
{
    int serial;// 线程序号
    char entity;// 线程类别(判断是读者还是写者线程)
    double delay;// 线程延迟时间
    double persist;// 线程读写操作时间
};
// 读者优先--读者线程
// P：读者线程信息
void RP_ReaderThread(void*p)
{
// 互斥变量
    HANDLE h_Mutex;
    h_Mutex=OpenMutex(MUTEX_ALL_ACCESS,FALSE,_T("mutex_for_readcount"));
    DWORD wait_for_mutex;// 等待互斥变量所有权
    DWORD m_delay;// 延迟时间
    DWORD m_persist;// 读文件持续时间
    int m_serial;// 线程序号
// 从参数中获得信息
    m_serial=((ThreadInfo*)(p))->serial;
    m_delay=(DWORD)(((ThreadInfo*)(p))->delay*INTE_PER_SEC);
    m_persist=(DWORD)(((ThreadInfo*)(p))->persist*INTE_PER_SEC);
    Sleep(m_delay);// 延迟等待
    printf("读线程%d 发出读请求.\n",m_serial);
// 等待互斥信号,保证对 ReadCount 的访问,修改互斥
    wait_for_mutex=WaitForSingleObject(h_Mutex,-1);
// 读者数目增加
    readcount++;
    if(readcount==1)
    {
// 第一个读者,等待资源
        EnterCriticalSection(&RP_Write);
    }
    ReleaseMutex(h_Mutex);// 释放互斥信号
// 读文件
    printf("读线程%d 开始读文件.\n",m_serial);
    Sleep(m_persist);
// 退出线程
    printf("读线程%d 结束读文件.\n",m_serial);
// 等待互斥信号,保证对 ReadCount 的访问,修改互斥
    wait_for_mutex=WaitForSingleObject(h_Mutex,-1);
// 读者数目减少
    readcount--;
    if(readcount==0)
    {
        LeaveCriticalSection(&RP_Write);// 如果所有的读者读完,唤醒写者
    }
    ReleaseMutex(h_Mutex);// 释放互斥信号
}
// 读者优先--写者线程
// P：写者线程信息
void RP_WriterThread(void*p)
{
    DWORD m_delay;// 延迟时间
    DWORD m_persist;// 写文件持续时间
    int m_serial;// 线程序号
// 从参数中获得信息
    m_serial=((ThreadInfo*)(p))->serial;
    m_delay=(DWORD)(((ThreadInfo*)(p))->delay*INTE_PER_SEC);
    m_persist=(DWORD)(((ThreadInfo*)(p))->persist*INTE_PER_SEC);
    Sleep(m_delay);
    printf("写线程%d 发出写请求***.\n",m_serial);
// 等待资源
    EnterCriticalSection(&RP_Write);
// 写文件
    printf("写线程%d 开始写文件.\n",m_serial);
    Sleep(m_persist);
// 退出线程
    printf("写线程%d 结束写文件.\n",m_serial);
// 释放资源
    LeaveCriticalSection(&RP_Write);
}
//////////////////////////////////////////////////////////////
// 读者优先处理函数
void ReaderPriority(char*file)
{
    DWORD n_thread=0;// 线程数目
    DWORD thread_ID;// 线程 ID
    DWORD wait_for_all;// 等待所有线程结束
// 互斥对象
    HANDLE h_Mutex;
    h_Mutex=CreateMutex(NULL,FALSE,_T("mutex_for_readcount"));
// 线程对象的数组
    HANDLE h_Thread[MAX_THREAD_NUM];
    ThreadInfo thread_info[MAX_THREAD_NUM];
    readcount=0;// 初始化 readcount
    InitializeCriticalSection(&RP_Write);// 初始化临界区
    std::ifstream inFile;
    inFile.open(file);
    if(inFile.rdstate()==std::ios::failbit)
    {
        printf("打开文件\"%s\"失败！请将\"%s\"放入程序目录下。\n",file,file);
        return;
    }
    printf("读者优先:\n\n");
    while(inFile)
    {
// 读入每一个读者,写者的信息
        inFile>>thread_info[n_thread].serial;
        inFile>>thread_info[n_thread].entity;
        inFile>>thread_info[n_thread].delay;
        inFile>>thread_info[n_thread++].persist;
        inFile.get();
    }
    for(int i=0;i<(int)(n_thread);i++)
    {
        if(thread_info[i].entity==READER||thread_info[i].entity=='r')
        {
            h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(RP_ReaderThread),&thread_info[i],
                                       0,&thread_ID);// 创建读者进程
        }
        else
        {
            h_Thread[i]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)(RP_WriterThread),&thread_info[i],
                                       0,&thread_ID);// 创建写线程
        }
    }
// 等待所有的线程结束
    wait_for_all=WaitForMultipleObjects(n_thread,h_Thread,TRUE,-1);
    printf("所有的读写线程结束操作.\n");
}
int main(int argc,char*argv[])
{
    ReaderPriority((char*)"input.txt");
    printf("\n 按任意键结束:");
    getch();
    return 0;
}
