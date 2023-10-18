#include<iostream>
using namespace std;
int main()
{
    int T,a,b,n,p;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        p=0;
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++)
        {
            if(i>a&&n-i<=b)
            {
                p++;
            }
        }
        cout<<p<<endl;
    }
    system("pause");
    return 0;
}