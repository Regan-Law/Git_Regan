#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
typedef struct Max// 资源的最大需求量
{
    int m_a;
    int m_b;
    int m_c;
} Max;
typedef struct Allocation// 已分配的资源数
{
    int a_a;
    int a_b;
    int a_c;
} Allocation;
typedef struct Need// 还需要的资源数
{
    int n_a;
    int n_b;
    int n_c;
} Need;
struct Available// 可利用的资源量
{
    int av_a;
    int av_b;
    int av_c;
} q;
struct pr// 定义一个结构
{
    char name;
    Max max;
    Allocation allocation;
    Need need;
    int finishflag;
} p[5];
char na[5];
void init()// 读入文件"input.txt"
{
    cout<<"各进程还需要的资源数 NEED："<<endl;
    FILE*fp;
    fp=fopen("input.txt","r+");// 打开文件"input.txt"
    for(int i=0;i<5;i++)
    {
        fscanf(fp,"%c%d%d%d%d%d%d\n",&p[i].name,&p[i].max.m_a,&p[i].max.m_b,&p[i].max.m_c,&p[i].allocation.a_a,&p[i].allocation.a_b,&p[i].allocation.a_c);
        p[i].need.n_a=p[i].max.m_a-p[i].allocation.a_a;
        p[i].need.n_b=p[i].max.m_b-p[i].allocation.a_b;
        p[i].need.n_c=p[i].max.m_c-p[i].allocation.a_c;
        cout<<p[i].name<<":"<<p[i].need.n_a<<" "<<p[i].need.n_b<<" "<<p[i].need.n_c<<endl;
    }
    fclose(fp);// 关闭文件
}
int fenpei()// 分配资源
{
    cout<<"Available:";
    cout<<q.av_a<<" "<<q.av_b<<" "<<q.av_c<<endl;
    int finishcnt=0,k=0,count=0;
    for(int j=0;j<5;j++)
    {
        p[j].finishflag=0;
    }
    while(finishcnt<5)
    {
        for(int i=0;i<5;i++)
        {
            if(p[i].finishflag==0&&q.av_a>=p[i].need.n_a&&q.av_b>=p[i].need.n_b&&q.av_c>=p[i].need.n_c)
            {
                q.av_a+=p[i].allocation.a_a;
                q.av_b+=p[i].allocation.a_b;
                q.av_c+=p[i].allocation.a_c;
                p[i].finishflag=1;
                finishcnt++;
                na[k++]=p[i].name;
                break;
            }
        }
        count++;// 禁止循环过多
        if(count>5)
        {
            return 0;
        }
    }
    return 1;
}
int shq()// 申请资源
{
    int m=0,i=0,j=0,k=0;// m 为进程号;i,j,k 为申请的三类资源数
    cout<<"请输入进程号和请求资源的数目!"<<endl;
    cout<<"如：进程号 资源 A B C"<<endl;
    cout<<" 0 2 0 2"<<endl;
    cin>>m>>i>>j>>k;
    if(i<=p[m].need.n_a&&j<=p[m].need.n_b&&k<=p[m].need.n_c)
    {
        if(i<=q.av_a&&j<=q.av_b&&k<=q.av_c)
        {
            p[m].allocation.a_a+=i;
            p[m].allocation.a_b+=j;
            p[m].allocation.a_c+=k;
            p[m].need.n_a=p[m].max.m_a-p[m].allocation.a_a;
            p[m].need.n_b=p[m].max.m_b-p[m].allocation.a_b;
            p[m].need.n_c=p[m].max.m_c-p[m].allocation.a_c;
            cout<<"各进程还需要的资源数 NEED:"<<'\n';
            for(int w=0;w<5;w++)
            {
                cout<<p[w].name<<":"<<p[w].need.n_a<<" "<<p[w].need.n_b<<" "<<p[w].need.n_c<<endl;
            }
            return 1;
        }
        else
        {
            cout<<"Request>Available 让进程"<<m<<"等待......"<<endl;
        }
    }
    else
    {
        cout<<"Request>Need,让进程"<<m<<"等待......"<<endl;
    }
    return 0;
}
int main()
{
    int flag=1;
    char c;
    cout<<"/********银 行 家 算 法********/ "<<endl;
    cout<<"确认已经在\"input.txt\"文档中正确输入各进程的有关信息后按回车键"<<endl;
    getch();
    init();
    q.av_a=10;// 各种资源的数量
    q.av_b=5;
    q.av_c=7;
    while(flag)
    {
        for(int i=0;i<5;i++)
        {
            q.av_a-=p[i].allocation.a_a;
            q.av_b-=p[i].allocation.a_b;
            q.av_c-=p[i].allocation.a_c;
        }
        if(fenpei())
        {
            cout<<"这样配置资源是安全的!"<<endl;
            cout<<"其安全序列是： ";
            for(int k=0;k<5;k++)
            {
                cout<<"-->"<<na[k];
            }
            cout<<endl;
            cout<<"有进程发出 Request 请求向量吗?(Enter y or Y)"<<endl;
            cout<<endl;
            c=getch();
            if(c=='y'||c=='Y')
            {
                if(shq())
                    continue;
                else
                    break;
            }
            else
                flag=0;
        }
        else
        {
            flag=0;
            cout<<"不安全!!!"<<endl;
        }
    }
    return 0;
}
