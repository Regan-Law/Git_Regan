#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t=-1e6;
    while(n--)
    {
        int x;
        cin>>x;
        if(x<0)
        {
            t=max(t,x);
            continue;
        }
        else
        {
            int c=sqrt(x);
            if(c*c!=x)
            {
                t=max(t,x);
            }
        }
    }
    cout<<t<<endl;
    system("pause");
    return 0;
}