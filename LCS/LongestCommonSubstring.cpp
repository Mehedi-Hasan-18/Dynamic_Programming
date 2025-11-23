// Problem Statement: Given two strings 's1' and 's2', find the length of the longest common substring. 


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    int mx_length = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];

                mx_length = max(dp[i][j],mx_length);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    cout << mx_length<<endl;

    return 0;
}
