#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int wt[n];
    for(int i=0;i<n;i++) cin >> wt[i];
    int sum;
    cin >> sum;
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 ){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(wt[i-1] <= j){
                dp[i][j] = (dp[i-1][j-wt[i-1]] || dp[i-1][j]);
            }
            else {
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    if(dp[n][sum]) cout <<"YES\n";
    else cout <<"NO\n";
    return 0;
}
