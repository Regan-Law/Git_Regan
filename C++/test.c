#include "stdio.h"
#define N 5
void main()
{
    int a[N];
    int *p=a;
    while(p<a+N)
        scanf("%d",p++);
    while(p>a)
        printf("%d",*(--p));
}