#include<iostream>
using namespace std;
#define Maxsize 30
typedef struct
{
    int data[30];
    int front;
    int rear;
} SqQueue;
//��ʼ������
void InitQueue(SqQueue*&q)
{
    q=new SqQueue;
    q->front=-1;
    q->rear=-1;
}
//ɾ������
void DestroyQueue(SqQueue*&q)
{
    delete q;
}
//�ж��Ƿ�Ϊ�ձ�
int QueueEmpty(SqQueue*q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
//���
int enQueue(SqQueue*&q,int e)
{
    q->rear=(q->rear+1)%Maxsize;
    if(q->rear==q->front)//����
        return 0;
    q->data[q->rear]=e;
    return 1;
}
//����
int deQueue(SqQueue*&q,int&e)
{
    if(q->front==q->rear)//�ӿ�
        return 0;
    q->front=(q->front+1)%Maxsize;
    e=q->data[q->front];
    return 1;
}
//����������Ա�ı��
void Number(int Fir_Last[],int n)
{
    int i;
    for(i=0;i<n;++i)
        Fir_Last[i]=i+1;
}
//�������Ŷ�
void QueueUp(SqQueue*&q,int Fir[],int n)
{
    int i;
    for(i=0;i<n;++i)
    {
        enQueue(q,Fir[i]);//��ÿ���˶����
    }
}
//�Ų鱨��Ϊm����
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
//������ӵ�˳��
void DispQueue(int Last[],int n)
{
    int i,k=0;
    for(i=0;i<n;++i)
    {
        cout<<Last[i]<<" ";
        k++;
        if(k%5==0)
            cout<<endl;//ÿ���5���ͻ���
    }
}
int main()
{
    int n,k;
    SqQueue*q;
    InitQueue(q);
    cout<<"�������ж��ٸ��ˣ�";
    cin>>n;
    cout<<endl;
    cout<<"������k����ֵ��";
    cin>>k;
    cout<<"������ӵ�˳��Ϊ��";
    cout<<endl;
    int x[n];
    Number(x,n);//�������˱��
    QueueUp(q,x,n);//���������Ŷ�
    SeekQueue(q,x,k);//Ѱ�ҳ�������
    DispQueue(x,n);//���˳��
    system("pause");
    return 0;
}
