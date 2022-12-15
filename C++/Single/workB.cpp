#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int n[N],max[N]={0},MAX=0;
    for(int i=0;i<N;i++)
    {
        cin>>n[i];
    }
    for(int i=0;i<N;i++)
    {
        int count=i;
        while(count<N)
        {
            max[i]+=n[count];
            count+=n[count];
        }
    }
    for(int i=0;i<N;i++)
    {
        if(max[i]>MAX)
        {
            MAX=max[i];
        }
    }
    cout<<MAX;
    system("pause");
    return 0;
}