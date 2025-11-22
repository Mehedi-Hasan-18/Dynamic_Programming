#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int arr[n];
    int range = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        range+=arr[i];
    } 

    bool dp[n+1][range+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<range+1;j++){
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = ((dp[i-1][j-arr[i-1]]) || dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    vector<int>v;
    for(int i=n;i<n+1;i++){
        for(int j=0;j<(range+1)/2;j++){
            if(dp[i][j]){
                v.push_back(j);
            }
        }
    }

    int mn = INT_MAX;
    for(int x : v){
        mn = min(mn,(range-(2*x)));
    }
    cout << mn;

    return 0;
}
