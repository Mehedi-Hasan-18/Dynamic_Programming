// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome.
// Example:
//   “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”.

#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int pd[1000][1000];

int isPalindrome(string &s, int i, int j)
{
    if (pd[i][j] != -1)
        return pd[i][j];

    int l = i, r = j;

    while (l < r)
    {
        if (s[l] != s[r])
            return pd[i][j] = 0;
        l++;
        r--;
    }

    return pd[i][j] = 1;
}

int solve(string s, int i, int j)
{
    if (i >= j || isPalindrome(s, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        //here we are forcing the left partition to be a palindrome otherwise we just skip the k. Because for palindrome we need 0 Cut.
        if (isPalindrome(s, i, k))
        {
            int tempAns = 1 + solve(s, k + 1, j);
            if (tempAns < ans)
                ans = tempAns;
        }
    }
    return dp[i][j] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    memset(pd, -1, sizeof(pd));

    cout << solve(s, 0, s.size() - 1);

    return 0;
}
