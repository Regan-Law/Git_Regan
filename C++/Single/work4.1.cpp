#include<iostream>
using namespace std;
#define MAXSIZE 100
#define X 2
//˳��ջ�Ľṹ��������
typedef struct
{
    int data[MAXSIZE];
    int top;
} SeqStack;
//����ǰ������
void initSeqStack(SeqStack*S);
int isEmpty(SeqStack*S);
void pushStack(SeqStack*S,int element);
int popStack(SeqStack*S,int element);
void conversion(SeqStack*S,int N);
void traverseStack(SeqStack*S);
//��ʼ��˳��ջ
void initSeqStack(SeqStack*S)
{
    S->top=-1;
    return;
}
//�ж�ջ�Ƿ�Ϊ��
int isEmpty(SeqStack*S)
{
    if(-1==S->top)
        return 1;
    else
        return 0;
}
//�ж�ջ�Ƿ�Ϊ��
int isFull(SeqStack*S)
{
    if(MAXSIZE==S->top)
        return 1;
    else
        return 0;
}
//˳��ջ��ѹջ����
void pushStack(SeqStack*S,int element)
{
    if(isFull(S))
    {
        printf("ջ����,�޷�����ѹջ!\n");
        return;
    }
    else
    {
        S->top++;
        S->data[S->top]=element;
        return;
    }
}
//˳��ջ�ĳ�ջ����
void popStack(SeqStack*S,int*element)
{
    if(isEmpty(S))
    {
        printf("ջ�ѿ�,�޷�������ջ!\n");
        return;
    }
    else
    {
*element=S->data[S->top];
        S->top--;
        return;
    }
}
//����ת��
void conversion(SeqStack*S,int number)
{
    int restNumber;
    while(number)
    {
        restNumber=number%X;
        pushStack(S,restNumber);
        number=number/X;
    }
    return;
}
//˳��ջ�ı�������
void traverseStack(SeqStack*S)
{
    if(isEmpty(S))
    {
        cout<<"ջΪ��!"<<endl;
        return;
    }
    for(int i=S->top;i>=0;i--)
    {
        cout<<S->data[i];
    }
    cout<<endl;
    return;
}
//������
int main()
{
    SeqStack S;
    int number;
    initSeqStack(&S);
    cout<<"������һ��ʮ��������:"<<endl;
    cin>>number;
    conversion(&S,number);
    cout<<"���Ķ�����ֵΪ:";
    traverseStack(&S);
    system("pause");
    return 0;
}