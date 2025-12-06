// Egg Dropping using Recursion
// Problem statement: You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

// If egg breaks at ith floor then it also breaks at all greater floors.
// If egg does not break at ith floor then it does not break at all lower floors.
// Unbroken egg can be used again.
// Note: You have to find minimum trials required to find the critical floor not the critical floor.

#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int solve(int e, int f)
{
    if (f == 0 || f == 1 || e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX;
    // for (int k = 1; k <= f; k++)
    // {
    //     int tempAns = 1 + max(solve(e - 1, k - 1), solve(e, f - k));

    //     mn = min(mn, tempAns);
    // }

    //Binary Search Work Better Here......
    int l = 1;
    int r = f;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int Break = solve(e - 1, mid - 1);
        int notBreak = solve(e, f - mid);

        int tempAns = 1 + max(Break, notBreak);

        ans = min(ans, tempAns);

        if (Break > notBreak)
            r = mid - 1;
        else
        {
            l = mid + 1;
        }
    }

    return dp[e][f] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int egg, floor;
    cin >> egg >> floor;

    memset(dp, -1, sizeof(dp));
    cout << solve(egg, floor);

    return 0;
}
