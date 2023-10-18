#include<stdlib.h>
#include "stdio.h"
#define MAX 5// 进程数量
#define RR 1// 时间片大小
struct pro
{
    int num;
    int arriveTime;
    int burst;
    int rt;// 记录进程被运行的次数
    struct pro*next;
};
int TOTALTIME;// 记录所有进程的总时间
// 函数声明
struct pro*creatList();
void insert(struct pro*head,struct pro*s);
struct pro*searchByAT(struct pro*head,int AT);
void del(struct pro*p);
int getCount(struct pro*head,int time);
struct pro*searchEnd(struct pro*head);
void move(struct pro*headF,struct pro*headT,int n);
struct pro*creatList()// 创建链表，按照进程的达到时间排列，记录所有进程信息
{
    struct pro*head=(struct pro*)malloc(sizeof(struct pro));
    head->next=NULL;
    struct pro*s;
    int i;
    TOTALTIME=0;
    for(i=0;i<MAX;i++)
    {
        s=(struct pro*)malloc(sizeof(struct pro));
        printf("请输入进程名:\n");
        scanf("%d",&(s->num));
        printf("请输入达到时间\n");
        scanf("%d",&(s->arriveTime));
        printf("请输入运行时间\n");
        scanf("%d",&(s->burst));
        TOTALTIME+=s->burst;// 计算总时间
        s->rt=1;// rt 的初始值为 1
        s->next=NULL;
        insert(head,s);
    }
    return head;// 到达队列中的进程按照到达时间的先后顺序排列
}
void insert(struct pro*head,struct pro*s)// 插入节点
{
    struct pro*p=searchByAT(head,s->arriveTime);
    s->next=p->next;
    p->next=s;
    return;
}
struct pro*searchByAT(struct pro*head,int AT)// 查找第一个到达时间大于等于 AT 的节点，返回其前一个指针
{
    struct pro*p,*q;
    p=head;
    q=head->next;
    while(q !=NULL&&q->arriveTime<=AT)
    {
        p=q;
        q=q->next;
    }
    return p;
}
void del(struct pro*p)// 删除 p 的下一个节点
{
    struct pro*tmp;
    tmp=p->next;
    p->next=tmp->next;
    free(tmp);
    return;
}
int getCount(struct pro*head,int time)// 产看在 time 之前到达但未移动到运行队列的进程
{
    int count=0;
    struct pro*s,*t;
    s=head;
    t=s->next;
    while(t !=NULL&&t->arriveTime<=time)
    {
        s=t;
        t=t->next;
        count++;// count 记录当前时刻到达的进程数
    }
    return count;
}
struct pro*searchEnd(struct pro*head)// 查找并返回循环队列的尾节点的前一个节点
{
    struct pro*p,*q;
    p=head;
    q=head->next;
    while(q->next !=head)
    {
        p=q;
        q=q->next;
    }
    return p;
}
void move(struct pro*headF,struct pro*headT,int n)// 将 headF 后的 n 个节点移动到循环队列 headT 中
{
    struct pro*r,*s,*t;
    s=headF;
    t=s->next;
    r=t;// r 记录要移动的第一个节点
    while(n>1)
    {
        t=t->next;
        n--;
    }
    s->next=t->next;// 以上完成从原队列中摘除相关节点，r，t 分别为第一个和最后一个节点
    s=searchEnd(headT);
    t->next=s->next;
    s->next=r;
}
void run(struct pro*head)
{
    int time=0;// 记录当前时间
    int newarrive;// 新到达进程数
    struct pro*runhead=(struct pro*)malloc(sizeof(struct pro));
    runhead->next=runhead;// 创建新的循环链表，存放当前就绪队列中的进程
    struct pro*p,*q;
    p=runhead;
    q=p->next;// q 记录当前应当运行的进程
    while(time<=TOTALTIME)
    {
        newarrive=getCount(head,time);
        if(newarrive>0)
            move(head,runhead,newarrive);// 将 head 后的 newarrive 个节点移动到 runhead 队列中
        if(runhead->next==runhead)// 就绪队列中没有进程
            time++;
        else if(q==runhead)
        {
            p=q;
            q=q->next;
        }
        else
        {
            printf("进程名%d\n",q->num);
            printf("到达时间:%d\n",q->arriveTime);
            if(q->rt==1)
                printf("响应时间:%d\n",time-q->arriveTime);
            else
                printf("第%d 次开始运行时间：%d\n",q->rt,time);
            if(q->burst<=RR)
            {
                time+=q->burst;
                printf("第%d 次运行结束时间：%d\n",q->rt,time);
                printf("周转时间:%d\n",time-q->arriveTime);
                printf("************************************\n");
                struct pro*tmp=q;
                q=q->next;
                p->next=q;
                free(tmp);
            }
            else// q->burst>RR
            {
                time+=RR;
                printf("第%d 次运行结束时间：%d\n",q->rt,time);
                printf("************************************\n");
                q->burst-=RR;
                q->rt++;
                p=q;
                q=q->next;
            }
        }
    }
}
int main()
{
    struct pro*head=creatList();
    printf("当前时间片大小为:%d\n",RR);
    run(head);
    return 0;
}
