#include <iostream>
#define MAX_SIZE 100000
#include <string.h>
using namespace std;
int main()
{
    int n, count_m=0, count_f=0;
A:
    cin >> n;
    if (n < 1 || n > MAX_SIZE)
    {
        cerr << "请重新输入" << endl;
        goto A;
    }
    char sex[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sex[i];
    }
    for (int i = 0; i < n; i++)
    {

        if (sex[i] == 'm')
        {
            count_m++;
        }
        if (sex[i] == 'f')
        {
            count_f++;
        }
    }
    if (count_f > count_m)
    {
        cout << (count_f - count_m);
    }
    else
        cout << (count_m - count_f);
    system("pause");
    return 0;
}