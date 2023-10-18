#include<iostream>
using namespace std;
#define MAXSIZE 100
#define X 2
//顺序栈的结构体类类型
typedef struct
{
    int data[MAXSIZE];
    int top;
} SeqStack;
//函数前置声明
void initSeqStack(SeqStack*S);
int isEmpty(SeqStack*S);
void pushStack(SeqStack*S,int element);
int popStack(SeqStack*S,int element);
void conversion(SeqStack*S,int N);
void traverseStack(SeqStack*S);
//初始化顺序栈
void initSeqStack(SeqStack*S)
{
    S->top=-1;
    return;
}
//判断栈是否为空
int isEmpty(SeqStack*S)
{
    if(-1==S->top)
        return 1;
    else
        return 0;
}
//判断栈是否为满
int isFull(SeqStack*S)
{
    if(MAXSIZE==S->top)
        return 1;
    else
        return 0;
}
//顺序栈的压栈操作
void pushStack(SeqStack*S,int element)
{
    if(isFull(S))
    {
        printf("栈已满,无法继续压栈!\n");
        return;
    }
    else
    {
        S->top++;
        S->data[S->top]=element;
        return;
    }
}
//顺序栈的出栈操作
void popStack(SeqStack*S,int*element)
{
    if(isEmpty(S))
    {
        printf("栈已空,无法继续出栈!\n");
        return;
    }
    else
    {
*element=S->data[S->top];
        S->top--;
        return;
    }
}
//进制转换
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
//顺序栈的遍历操作
void traverseStack(SeqStack*S)
{
    if(isEmpty(S))
    {
        cout<<"栈为空!"<<endl;
        return;
    }
    for(int i=S->top;i>=0;i--)
    {
        cout<<S->data[i];
    }
    cout<<endl;
    return;
}
//主函数
int main()
{
    SeqStack S;
    int number;
    initSeqStack(&S);
    cout<<"请输入一个十进制整数:"<<endl;
    cin>>number;
    conversion(&S,number);
    cout<<"它的二进制值为:";
    traverseStack(&S);
    system("pause");
    return 0;
}