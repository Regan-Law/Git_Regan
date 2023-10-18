#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXSIZE 200
int dp[MAXSIZE][MAXSIZE];
class Solution
{
public:
    int getLCS(string &s1)
    {
        string s2(s1);
        reverse(s2.begin(), s2.end());
        int len = s1.length();
        int maxlen = 0, half, count = 0, wrong = -1;
        memset(dp, 0, sizeof dp);
        if(s1.length()==1)
        {
            return 0;
        }
        else
        for (int i = 0; i < len; i++)
        {
            if (s2[0] == s1[i])
            {
                while (i < len)
                    dp[0][i++] = 1;
            }
            else
                dp[0][i] = 0;
        }

        for (int i = 0; i < len; i++)
        {
            if (s2[i] == s1[0])
            {
                while (i < len)
                    dp[i++][0] = 1;
            }
            else
                dp[i][0] = 0;
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j < len; j++)
            {
                if (s1[j] == s2[i])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                maxlen = max(maxlen, dp[i][j]);
            }
            if (s1.length() % 2 == 0)
            {
                half = s1.length() / 2;
                for (int k = 0; k < half; k++)
                {
                    if (s1[k] == s1[half + k])
                    {
                        count++;
                    }
                }
                string s3=s1.substr(0,half);
                if (count == half && checkDifferent(s3) == 1)
                {
                    return wrong;
                    break;
                }
            }
        }
        if(maxlen==0)
        {
        return -1;}
        return len - maxlen;
    }
    int checkDifferent(string iniString)
    {
        int f = -1, t = 1;
        int a[256] = {0};
        int len = iniString.length(), i;
        if (len > 256)
            return f;
        for (i = 0; i < len; i++)
        {
            int x = iniString[i];
            a[x]++;
            if (a[x] > 1)
                return f;
        }
        return t;
    }
};

int main()
{
    int t;
    cin >> t;
    int n[t];
    string s[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        cin >> s[i];
    }
    Solution solution;

    for (int i = 0; i < t; i++)
    {
        cout << solution.getLCS(s[i]) << endl;
    }
    system("pause");
    return 0;
}