#include<iostream>
using namespace std;
typedef struct wildelf
{
    int need;
    int damage;
} wildelf;
int main()
{
    int A,S,D;
    cin>>A>>S>>D;
    wildelf wild[D];
    for(int i=0;i<D;i++)
    {
        cin>>wild[i].need;
        cin>>wild[i].damage;
    }
    system("pause");
    return 0;
}