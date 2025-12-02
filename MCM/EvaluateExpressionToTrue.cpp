// Given a boolean expression s that contain symbols and operators. The task is to count the number of ways we can parenthesize the expression so that the value of the expression evaluates to true.

// https://www.geeksforgeeks.org/dsa/boolean-parenthesization-problem-dp-37/

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001][2];

int solve(string s, int i, int j, bool isTrue)
{

    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue)
        {
            if (s[i] == 'T')
                return 1;
            else
                return 0;
        }
        else
        {
            if (s[i] == 'F')
                return 1;
            else
                return 0;
        }
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;

    for (int k = i + 1; k < j; k += 2)
    {
        int leftTrue, leftFalse, rightTrue, rightFalse;

        if (dp[i][k - 1][0] != -1)
            leftFalse = dp[i][k - 1][0];
        else
            leftFalse = solve(s, i, k - 1, false);

        if (dp[i][k - 1][1] != -1)
            leftTrue = dp[i][k - 1][1];
        else
            leftTrue = solve(s, i, k - 1, true);

        if (dp[k + 1][j][0] != -1)
            rightFalse = dp[k + 1][j][0];
        else
            rightFalse = solve(s, k + 1, j, false);

        if (dp[k + 1][j][1] != -1)
            rightTrue = dp[k + 1][j][1];
        else
            rightTrue = solve(s, k + 1, j, true);

        if (s[k] == '&')
        {
            if (isTrue)
                ans = ans + leftTrue * rightTrue;
            else
            {
                ans = ans + leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans = ans + leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            else
                ans = ans + leftFalse * rightFalse;
        }
        else
        {
            if (isTrue)
            {
                ans = ans + leftFalse * rightTrue + leftTrue * rightFalse;
            }
            else
            {
                ans = ans + leftFalse * rightFalse + leftTrue * rightTrue;
            }
        }
    }
    return dp[i][j][isTrue] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, s.size() - 1, true);

    return 0;
}
