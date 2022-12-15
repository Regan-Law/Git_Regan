#include "string.h"
#include<iostream>
#define n 10// 假定系统可容纳的作业数量为 N
typedef struct jcb
{
    char name[4];// 作业名
    int length;// 作业长度，所需内存大小
    int printer;// 作业执行所需的打印机数量
    int tape;// 作业执行所需的磁带机数量
    int runtime;// 作业估计运行时间
    int waittime;// 作业在系统中的等待时间
    int next;// 指向下一个作业控制块的指针
} JCB;
int head;
int tape,printer;
long memory;
JCB jobtable[n];// 作业表
int jobcount=0;// 系统内现有作业数量
void shedule()
{
    float xk,k;
    int p,q,s,t;
    do
    {
        p=head;
        q=s=-1;
        k=0;
        while(p !=-1)
        {
// 系统可用资源数是否满足作业需求
            if(jobtable[p].length<=memory&&jobtable[p].tape<=tape&&jobtable[p].printer<=printer)
            {
                xk=(float)(jobtable[p].waittime+jobtable[p].runtime)/jobtable[p].runtime;
                if(q==0||xk>k)
// 满足条件的第一个作业或者作业 q 的响应比小于作业 P 的响应比
                {
                    k=xk;
                    q=p;
                    t=s;
                }
            }
            s=p;
            p=jobtable[p].next;// 指针后移
        }
        if(q !=-1)
        {
            if(t==-1)// 是作业队列的第一个
                head=jobtable[head].next;
            else
                jobtable[t].next=jobtable[q].next;
            memory=memory-jobtable[q].length;// 为作业分配内存空间
            tape=tape-jobtable[q].tape;// 为作业分配磁带机
            printer=printer-jobtable[q].printer;// 为作业分配打印机
            printf("选中的作业的作业名：%s\n",jobtable[q].name);
        }
    }while(q !=-1);
}
int main()
{
    char name[4];
    int size,tcount,pcount,wtime,rtime;
    int p;
    memory=65536;// 系统数据初始化
    tape=4;
    printer=2;
    head=-1;
    printf("请输入作业相关数据（以作业大小为负数停止输入）：\n");// 输入数据，建立队列
    printf("输入作业名 作业大小 磁带机数 打印机数 等待时间 估计运行时间\n");
    scanf("%s%d%d%d%d%d",name,&size,&tcount,&pcount,&wtime,&rtime);
    while(size !=-1)
    {// 创建 JCB
        if(jobcount<n)
            p=jobcount;
        else
        {
            printf("无法在创建作业\n");
            break;
        }
        jobcount++;
        strcpy(jobtable[p].name,name);// 填写作业内容
        jobtable[p].length=size;
        jobtable[p].printer=pcount;
        jobtable[p].tape=tcount;
        jobtable[p].runtime=rtime;
        jobtable[p].waittime=wtime;
        jobtable[p].next=head;// 挂入作业队队首
        head=p;
        printf("输入作业名 作业大小 磁带机数 打印机数 等待时间 估计运行时间\n");// 输入数据
        scanf("%s%d%d%d%d%d",name,&size,&tcount,&pcount,&wtime,&rtime);
    }
    shedule();// 进行作业调度
    return 0;
}