// Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

// Examples:

// Input: X = "AGGTAB",  Y = "GXTXAYB"
// Output: "AGXGTXAYB" OR "AGGXTXAYB"
// OR Any string that represents shortest
// supersequence of X and Y

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = n;
    int j = m;
    string scs = "";

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            scs.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else
        {
            //duita letter aksate add kora jabe na. first konta add hobe seta dp table er value dekhe bujte hobe and then je value the add hobe sudu oitare i/j er value the dicrease hobe.so other one remain same so that we can compare the letter agin and keep going. That's the reason we can not add two letter same time and the move the pointer.
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                scs.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                scs.push_back(str2[j - 1]);
                j--;
            }
        }
    }

    while (i > 0)
    {
        scs.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        scs.push_back(str2[j - 1]);
        j--;
    }

    reverse(scs.begin(), scs.end());
    cout << scs;

    return 0;
}
