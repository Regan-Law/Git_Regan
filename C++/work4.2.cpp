#include<iostream>
using namespace std;
#define Maxsize 30
typedef struct
{
    int data[30];
    int front;
    int rear;
} SqQueue;
//初始化队列
void InitQueue(SqQueue*&q)
{
    q=new SqQueue;
    q->front=-1;
    q->rear=-1;
}
//删除队列
void DestroyQueue(SqQueue*&q)
{
    delete q;
}
//判断是否为空表
int QueueEmpty(SqQueue*q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
//入队
int enQueue(SqQueue*&q,int e)
{
    q->rear=(q->rear+1)%Maxsize;
    if(q->rear==q->front)//队满
        return 0;
    q->data[q->rear]=e;
    return 1;
}
//出队
int deQueue(SqQueue*&q,int&e)
{
    if(q->front==q->rear)//队空
        return 0;
    q->front=(q->front+1)%Maxsize;
    e=q->data[q->front];
    return 1;
}
//建立所有人员的编号
void Number(int Fir_Last[],int n)
{
    int i;
    for(i=0;i<n;++i)
        Fir_Last[i]=i+1;
}
//所有人排队
void QueueUp(SqQueue*&q,int Fir[],int n)
{
    int i;
    for(i=0;i<n;++i)
    {
        enQueue(q,Fir[i]);//将每个人都入队
    }
}
//排查报数为m的人
void SeekQueue(SqQueue*&q,int Last[],int m)
{
    int i=0,j=0;
    int e;
    while(!QueueEmpty(q))
    {
        i++;
        deQueue(q,e);
        if(i==m)
        {
            Last[j]=e;
            i=0,j++;
        }
        else
        {
            enQueue(q,e);
        }
    }
}
//输出出队的顺序
void DispQueue(int Last[],int n)
{
    int i,k=0;
    for(i=0;i<n;++i)
    {
        cout<<Last[i]<<" ";
        k++;
        if(k%5==0)
            cout<<endl;//每输出5个就换行
    }
}
int main()
{
    int n,k;
    SqQueue*q;
    InitQueue(q);
    cout<<"请输入有多少个人：";
    cin>>n;
    cout<<endl;
    cout<<"请输入k的数值：";
    cin>>k;
    cout<<"则其出队的顺序为：";
    cout<<endl;
    int x[n];
    Number(x,n);//给所有人编号
    QueueUp(q,x,n);//所有人先排队
    SeekQueue(q,x,k);//寻找出队序列
    DispQueue(x,n);//输出顺序
    system("pause");
    return 0;
}
