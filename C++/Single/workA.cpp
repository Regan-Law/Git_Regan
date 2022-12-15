#include<iostream>
using namespace std;
int main()
{
    int xA,yA,xB,yB,xO,yO,x,y;
    cin>>xA>>yA>>xB>>yB>>xO>>yO;
    if(xA>xB)
    {
        x=xA-xB;
    }
    else 
    {
        x=xB-xA;
    }
    if(yA>yB)
    {
        y=yA-yB;
    }
    else
    {
        y=yB-yA;
    }
    cout<<x+y;
    system("pause");
    return 0;
}