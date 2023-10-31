#include "stdio.h"
#include "string.h"
int main()
{
    char c[]="\t\v\\\0\will\n";
    char b[]="fegweg\0wefnlwefj";
    printf("%llu,%llu",strlen(c), strlen(b));
    return 0;
}