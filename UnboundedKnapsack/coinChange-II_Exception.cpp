// Given an array of coins[] of size n and a target value sum, where coins[i] represent the coins of different denominations. You have an infinite supply of each of the coins. The task is to find the minimum number of coins required to make the given value sum. If it is not possible to form the sum using the given coins, return -1.


// This is a exceptional problem . For this problem you need to initialize to row and except 1 or 0 you need to initialize with INT_MAX-1; why -1 ? Bcz when you add 1 so that it dosen't exceed int boundary.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    int sum;
    cin >> sum;

    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (i != 0 && j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < 2; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j % coin[0] == 0)
            {
                dp[1][j] = j / coin[0];
            }
            else
            {
                dp[1][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min(((dp[i][j - coin[i - 1]]) + 1), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][sum] == INT_MAX || dp[n][sum]==INT_MAX-1)
        cout << -1 << endl;
    else
        cout << dp[n][sum] << endl;

    return 0;
}