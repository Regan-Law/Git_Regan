#include<iostream>
using namespace std;
void Print(int bc[],int blockCount)
{
    for(int i=0;i<blockCount;i++)
    {
        cout<<bc[i]<<" ";
    }
    cout<<endl;
}
int Travel(int bc[],int blockCount,int x)
{
    int index=-1;
    int i;
    for(i=0;i<blockCount;i++)
    {
        if(bc[i]==x)
        {
            index=i;
            break;
        }
    }
    return index;
}
void FIFO(int pc[],int bc[],int pageCount,int blockCount)
{
    cout<<"0：FIFO 置换算法"<<endl;
    int i;
    if(pageCount<=blockCount)
    {
        cout<<"缺页次数为"<<0<<endl;
        cout<<"缺页率为"<<0<<endl;
    }
    else
    {
        int noPage=0;
        int p=0;
        for(i=0;i<pageCount;i++)
        {
            cout<<"引用页："<<pc[i]<<endl;
            if(Travel(bc,blockCount,pc[i])==-1)// 页面不在内存
            {
                if(i<blockCount)// 预调页
                {
                    bc[i]=pc[i];
                }
                else
                {
                    bc[p%blockCount]=pc[i];// 页面不在内存，淘汰最先进入的页面
                    p++;
                }
                noPage++;
                cout<<"物理块情况：";
                Print(bc,blockCount);
            }
            cout<<endl;
        }
        cout<<"缺页次数为:"<<noPage<<endl;
        cout<<"缺页率为:"<<(float)noPage/pageCount<<endl;
    }
}
int FoundMaxNum(int a[],int n)
{
    int k,j;
    k=a[0];
    j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=k)
        {
            k=a[i];
            j=i;
        }
    }
    return j;
}
void LRU(int pc[],int bc[],int pageCount,int blockCount)
{
    cout<<"1：LRU 置换算法 "<<endl;
    if(pageCount<=blockCount)
    {
        cout<<"缺页次数为"<<0<<endl;
        cout<<"缺页率为"<<0<<endl;
    }
    else
    {
        int noPage=0;
        int i,j,m;
        int*bc1=new int[blockCount];
        for(i=0;i<blockCount;i++)
        {
            bc1[i]=0;
        }
        for(i=0;i<pageCount;i++)
        {
            cout<<"引用页："<<pc[i]<<endl;
            if(Travel(bc,blockCount,pc[i])==-1)// 页面不在内存
            {
                if(i<blockCount)// 预调页
                {
                    bc[i]=pc[i];
                    for(int p=0;p<=i;p++)
                    {
                        bc1[p]++;
                    }
                }
                else// 淘汰最近最久未使用的页面
                {
                    for(j=0;j<blockCount;j++)
                    {
                        bc1[j]++;
                    }
                    int k=FoundMaxNum(bc1,blockCount);
                    bc[k]=pc[i];
                    bc1[k]=1;
                }
                noPage++;
                cout<<"物理块情况：";
                Print(bc,blockCount);
            }
            else// 页面在内存
            {
                if(i<blockCount)
                {
                    for(j=0;j<=i;j++)
                    {
                        bc1[j]++;
                    }
                    for(m=0;m<i;m++)
                    {
                        if(bc[m]==pc[i])
                        {
                            break;
                        }
                    }
                    bc1[m]=1;
                    bc[m]=pc[i];
                }
                else
                {
                    for(j=0;j<blockCount;j++)
                    {
                        bc1[j]++;
                    }
                    for(m=0;m<blockCount;m++)
                    {
                        if(bc[m]==pc[i])
                        {
                            break;
                        }
                    }
                    bc1[m]=1;
                    bc[m]=pc[i];
                }
            }
            cout<<endl;
        }
        cout<<"缺页次数为:"<<noPage<<endl;
        cout<<"缺页率为:"<<(float)noPage/pageCount<<endl;
        delete bc1;
    }
}
void Optiomal(int pc[],int bc[],int pageCount,int blockCount)
{
    cout<<"2：最佳置换算法"<<endl;
    if(pageCount<=blockCount)
    {
        cout<<"缺页次数为"<<0<<endl;
        cout<<"缺页率为"<<0<<endl;
    }
    else
    {
        int noPage=0;
        int i,j,k;
        for(i=0;i<pageCount;i++)
        {
            cout<<"引用页："<<pc[i]<<endl;
            if(Travel(bc,blockCount,pc[i])==-1)// 页面不在内存
            {
                if(i<blockCount)// 预调页
                {
                    bc[i]=pc[i];
                }
                else// 页面置换
                {
                    int max=0;
                    int blockIndex;
                    for(j=0;j<blockCount;j++)
                    {
                        for(k=i;k<pageCount;k++)
                        {
                            if(bc[j]==pc[k])
                            {
                                break;
                            }
                        }
                        if(k>=max)
                        {
                            max=k;
                            blockIndex=j;
                        }
                    }
                    bc[blockIndex]=pc[i];
                }
                noPage++;
                cout<<"物理块情况：";
                Print(bc,blockCount);
            }
            cout<<endl;
        }
        cout<<"缺页次数为:"<<noPage<<endl;
        cout<<"缺页率为:"<<(float)noPage/pageCount<<endl;
    }
}
void NRU(int pc[],int bc[],int pageCount,int blockCount)
{
    cout<<"3：Clock 置换算法 "<<endl;
    if(pageCount<=blockCount)
    {
        cout<<"缺页次数为"<<0<<endl;
        cout<<"缺页率为"<<0<<endl;
    }
    else
    {
        int noPage=0;
        int i,j;
        int*bc1=new int[blockCount];
        for(i=0;i<blockCount;i++)
// 访问位初始化
        {
            bc1[i]=0;
        }
        int replace=0;
        for(i=0;i<pageCount;i++)
        {
            cout<<"引用页："<<pc[i]<<endl;
            int index=Travel(bc,blockCount,pc[i]);
            if(index==-1)// 页面不在内存
            {
                for(j=0;j<blockCount;j++)// 查找访问位为0 的页面
                {
                    if(bc1[replace]==1)
                    {
                        bc1[replace]=0;
                        replace=(replace+1)%blockCount;
                    }
                    else
                    {
                        break;
                    }
                }
                bc[replace]=pc[i];
                bc1[replace]=1;
                replace=(replace+1)%blockCount;
                noPage++;
                cout<<"物理块情况：";
                Print(bc,blockCount);
                cout<<"标志位情况：";
                Print(bc1,blockCount);
            }
            else
            {
                bc1[index]=1;
                replace=(index+1)%blockCount;
                cout<<"物理块情况：";
                Print(bc,blockCount);
                cout<<"标志位情况：";
                Print(bc1,blockCount);
            }
            cout<<endl;
        }
        cout<<"缺页次数为:"<<noPage<<endl;
        cout<<"缺页率为:"<<(float)noPage/pageCount<<endl;
        delete bc1;
    }
}
int main()
{
    int pageCount,blockCount,i;
    cout<<"输入页面数"<<endl;
    cin>>pageCount;
    int*pc=new int[pageCount];
    cout<<"输入页面走向"<<endl;
    for(i=0;i<pageCount;i++)
    {
        cin>>pc[i];
    }
    cout<<"输入物理块数"<<endl;
    cin>>blockCount;
    cout<<"0：FIFO 置换算法 "<<endl;
    cout<<"1：LRU 置换算法 "<<endl;
    cout<<"2：最佳置换算法"<<endl;
    cout<<"3：Clock 置换算法 "<<endl;
    cout<<"按数字选择算法类别："<<endl;
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            int*bc=new int[blockCount];
            FIFO(pc,bc,pageCount,blockCount);
            delete bc;
        }
        else if(n==1)
        {
            int*bc=new int[blockCount];
            LRU(pc,bc,pageCount,blockCount);
            delete bc;
        }
        else if(n==2)
        {
            int*bc=new int[blockCount];
            Optiomal(pc,bc,pageCount,blockCount);
            delete bc;
        }
        else if(n==3)
        {
            int*bc=new int[blockCount];
            for(i=0;i<blockCount;i++)
            {
                bc[i]=-1;
            }
            NRU(pc,bc,pageCount,blockCount);
            delete bc;
        }
        else
            break;
    }
    delete pc;
    return 0;
}