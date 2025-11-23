// 0-1 Knapsack and Unbounded Knapsack is almost same just the difference is if i take a item in unbounded kanpsack the item i can take one's more means the item is not process yet.but in 0-1 knapsack no matter i take the element or not the element is processed. i need to move to the next element.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++) cin >> wt[i];
    for(int i=0;i<n;i++) cin >> val[i];

    int w;cin>>w;

    int dp[n+1][w+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1] <= j){
                //the main difference is here if i can take a element in unbounded knapsack i can take it once more that's why i need to call the recursion with dp[i] not dp[i-1].But for 0-1 knapsack i take the element or not take dosen't matter the element is processed.that's why dp[i-1].
                // 0-1 knapsack : dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][w];

    return 0;
}
