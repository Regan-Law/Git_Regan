#include "stdio.h"
int main()
{
    int y=2,a=1;
    while(y--!=-1){
        do{
            a*=y;
            a++;
        }while(y--);
    }
    printf("%d,%d",a,y);
    return 0;
}