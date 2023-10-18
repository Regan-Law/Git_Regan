#include<iostream>
using namespace std;
int main()
{
    int r;
    int c;
    int n;
    int j;
    int b=1;
    int ex[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ex[i];
    }
    for(int i=0;i<n;i++)
    {
        for(j=1;b;j++)
        {
            if(j*j==ex[i])
            {
                c=1;
                r=j;
                cout<<r<<" "<<c<<endl;
                break;
            }
            if(j*j<ex[i]&&ex[i]<(j+1)*(j+1))
            {
                if(ex[i]<=(j+1)*(j+1)-j)
                {
                    c=j+1;
                    r=j+1-((j+1)*(j+1)-j-ex[i]);
                    cout<<r<<" "<<c<<endl;
                    break;
                }
                if(ex[i]>(j+1)*(j+1)-j)
                {
                    r=j+1;
                    c=j+1-(ex[i]-(j+1)*(j+1)+j);
                    cout<<r<<" "<<c<<endl;
                    break;
                }
            }    
        }
    }

    system("pause");
    return 0;
}