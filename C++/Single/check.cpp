#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
 
 
//自底向顶的动态规划
int LCS(string str1, string str2, int n1, int n2)
{
    vector<vector<int>> nVec(n1+1);
    for(int i = 0; i < n1+1; ++i)
    {
        nVec[i].assign(n2+1, -1);
    }
    for(int i = 0; i < n2+1;++i)
    {
        nVec[0][i] = 0;
 
    }  
    for(int i = 0; i < n1+1; ++i)
    {
        nVec[i][0] = 0;
    }
    for(int i = 1; i <= n1;++i)
    {
        for(int j = 1; j <= n2;++j)
        {
            if(str1[i-1] == str2[j-1])
            {
                nVec[i][j] = nVec[i - 1][j - 1] + 1;
 
            }
            else
            {
                nVec[i][j] = max(nVec[i][j - 1], nVec[i - 1][j]);
            }
        }
    }
    return nVec[n1][n2];
}
int main()
{
    string str;
    while(cin>>str){
        string::size_type nLen = str.size();
        string str1 = str;
        reverse(str1.begin(),str1.end());
        cout<<nLen - LCS(str,str1,nLen,nLen)<<endl;
    }system("pause");
    return 0;
}