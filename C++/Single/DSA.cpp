#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define maxsize 100
using namespace std;
// 先来先服务调度算法
void FCFS(int array[],int m)
{
    int sum=0,j,i,now;
    cout<<"请输入当前的磁道号：";
    cin>>now;
    for(i=0;i<m;i++)
    {
        cout<<array[i]<<" ";
    }
    sum+=abs(now-array[0]);
    for(i=0,j=1;j<m;i++,j++)
    {
        sum+=abs(array[j]-array[i]);
    }
    cout<<"移动的总道数： "<<sum<<endl;
}
// 最短寻道时间优先调度算法
void ShortPath(int array[],int m)
{
    int temp;
    int k=1;
    int now,l,r;
    int i,j,sum=0;
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
        {
            if(array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    for(i=0;i<m;i++)
    {
        cout<<array[i]<<" ";
    }/*排序*/
    cout<<"请输入当前的磁道号：";
    cin>>now;
    if(array[m-1]<=now)
    {
        for(i=m-1;i>=0;i--)
            cout<<array[i]<<" ";
        sum=now-array[0];
    }
    else if(array[0]>=now)
    {
        for(i=0;i<m;i++)
            cout<<array[i]<<" ";
        sum=array[m-1]-now;
    }
    else
    {
        while(array[k]<now)
        {
            k++;
        }
        l=k-1;
        r=k;
/*确定当前磁道在已排的序列中的位置，后面的算法都用到了，可以直接复杂后少量修改，节
                        省时间。*/
        while((l>=0)&&(r<m))
        {
            if((now-array[l])<=(array[r]-now))
            {
                cout<<array[l]<<" ";
                sum+=now-array[l];
                now=array[l];
                l=l-1;
            }
            else
            {
                cout<<array[r]<<" ";
                sum+=array[r]-now;
                now=array[r];
                r=r+1;
            }
        }
        if(l=-1)
        {
            for(j=r;j<m;j++)
            {
                cout<<array[j]<<" ";
            }
            sum+=array[m-1]-array[0];
        }
        else
        {
            for(j=l;j>=0;j--)
            {
                cout<<array[j]<<" ";
            }
            sum+=array[m-1]-array[0];
        }
    }
    cout<<"移动的总道数： "<<sum<<endl;
}
// 电梯调度算法
void Elevator(int array[],int m)// 先</A>要给出当前磁道号和移动臂的移动方向
{
    int temp;
    int k=1;
    int now,l,r,d;
    int i,j,sum=0;
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
        {
            if(array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    for(i=0;i<m;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"请输入当前的磁道号： ";
    cin>>now;
    if(array[m-1]<=now)
    {
        for(i=m-1;i>=0;i--)
            cout<<array[i]<<" ";
        sum=now-array[0];
    }
    else if(array[0]>=now)
    {
        for(i=0;i<m;i++)
            cout<<array[i]<<" ";
        sum=array[m-1]-now;
    }
    else
    {
        while(array[k]<now)
        {
            k++;
        }
        l=k-1;
        r=k;
        cout<<"请输入当前移动臂的移动的方向(1 表示向内 ，0 表示向外):";
        cin>>d;
        if(d==0)
        {
            for(j=l;j>=0;j--)
            {
                cout<<array[j]<<" ";
            }
            for(j=r;j<m;j++)
            {
                cout<<array[j]<<" ";
            }
            sum=now-2*array[0]+array[m-1];
        }
        else
        {
            for(j=r;j<m;j++)
            {
                cout<<array[j]<<" ";
            }
            for(j=l;j>=0;j--)
            {
                cout<<array[j]<<" ";
            }
            sum=-now-array[0]+2*array[m-1];
        }
    }
    cout<<"移动的总道数： "<<sum<<endl;
}
// 圆形电梯调度算法
void CSCAN(int array[],int m)
{
    int sum=0,index=0,now,order;
    cout<<"请输入当前的的磁道号:";
    cin>>now;
    cout<<endl<<"请输入当前移动臂的移动的方向(1 表示向内 ，0 表示向外):";
    cin>>order;
    int arr[m];// 新建一个arr数组复制array的所有元素
// 先进行选择排序，元将素由大到小排列
    for(int i=0;i<m;i++)
    {
        arr[i]=array[i];
    }
    for(int i=0;i<m;i++)
    {
        int k=i;
        for(int j=i;j<m;j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
    int min=abs(now-arr[0]);
    for(int i=0;i<m;i++)
    {
        if(abs(now-arr[i])<min)
        {
            min=abs(now-arr[i]);
            index=i;
        }
    }
    int left,right;
    if(arr[index]>now)
    {
        right=index;
        left=index-1;
    }
    else
    {
        left=index;
        right=index+1;
    }
    if(order==0)
    {
        sum+=abs(now-arr[left]);
        for(int i=left;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
// 直接移动到最右端，然后才继续向左处理
        for(int i=m-1;i>=right;i--)
        {
            cout<<arr[i]<<" ";
        }
        sum+=abs(arr[left]-arr[0])+abs(arr[m-1]-arr[0])+abs(arr[m-1]-arr[right]);
    }
    else if(order==1)
    {
        sum+=abs(now-arr[right]);
        for(int i=right;i<m;i++)
        {
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=left;i++)
        {
            cout<<arr[i]<<" ";
        }
        sum+=abs(arr[m-1]-arr[right])+abs(arr[m-1]-arr[0])+abs(arr[left]-arr[0]);
    }
    else
    {
        cout<<"输入磁头移动的方向有误"<<endl;
    }

    cout<<"移动的总道数:"<<sum<<endl;
}
int main()
{
    int c;
    FILE*fp;
    int cidao[maxsize];
    int i=0,count;
    fp=fopen("cidao.txt","r+");
    if(fp==NULL)
    {
        cout<<"文件打不开!"<<endl;
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d",&cidao[i]);
        i++;
    }
    count=i;
    for(i=0;i<count;i++)
    {
        printf("%5d",cidao[i]);
    }
    cout<<endl;
    while(1)
    {
        cout<<endl<<"系统的菜单如下："<<endl;
        printf("1. 先来先服务 2. 最短寻道时间优先 3. 电梯调度 4. 圆形电梯调度");
        cout<<endl;
        printf("5. 退出");
        cout<<endl;
        cout<<"请选择：";
        cin>>c;
        if(c>4)
            break;
        switch(c)
        {
        case 1:
            FCFS(cidao,count);
            break;
        case 2:
            ShortPath(cidao,count);
            break;
        case 3:
            Elevator(cidao,count);
            break;
        case 4:
            CSCAN(cidao,count);
            break;
        }
    }
}