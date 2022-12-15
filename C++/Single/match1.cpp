#include<iostream>
using namespace std;
int main()
{
    int a=1;
    int s[10000];
    for(int i=0;i<10000;i++)
    {
        if(0<i<3)
        {
            for( i=1;i<3;i++)
            {
                s[a]=i;
                a++;
            }
        }
        if(2<i<10)
        {
            for( i=3;i<10;i++)
            {
                if(i%3 !=0)
                {
                    s[a]=i;
                    a++;
                }
            }
        }
        if(9<i<100)
        {
            for( i=10;i<100;i++)
            {
                if(i%3 !=0&&i%10 !=3)
                {
                    s[a]=i;
                    a++;
                }
            }
        }
        if(99<i<1000)
        {
            for( i=100;i<1000;i++)
            {
                if(i%3 !=0&&i%10 !=3)
                {
                    s[a]=i;
                    a++;
                }
            }
        }
        if(999<i<10000)
        {
            for( i=1000;i<10000;i++)
            {
                if(i%3 !=0&&i%10 !=3)
                {
                    s[a]=i;
                    a++;
                }
            }
        }
        if(a==1000)
        {
            break;
        }
    }
    int f;
    cin>>f;
    if(0<f<1001)
    {
        cout<<s[f];
    }
    system("pause");
    return 0;
}