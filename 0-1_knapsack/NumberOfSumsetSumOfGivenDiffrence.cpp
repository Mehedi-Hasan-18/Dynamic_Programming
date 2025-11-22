#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n];
    int sumOfarray = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sumOfarray += arr[i];
    }
    int diff;
    cin >> diff;
    int sumOfSubset1 = (diff + sumOfarray) / 2;
    if (diff > sumOfarray || (diff + sumOfarray) % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int dp[n + 1][sumOfSubset1 + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sumOfSubset1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sumOfSubset1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        cout << dp[n][sumOfSubset1];
    }

    return 0;
}
