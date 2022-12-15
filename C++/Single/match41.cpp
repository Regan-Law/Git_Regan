#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s[n];
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int min=1e6;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]>s[j])
            {
                x=s[i]-s[j];
                if(min>x)
                {
                    min=x;
                }
            }
            else
            {
                x=s[j]-s[i];
                if(min>x)
                {
                    min=x;
                }
            }
        }
    }
    cout<<min;
    system("pause");
    return 0;
}