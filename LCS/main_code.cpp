// Variation: Longest Common Subsequence (LCS) and Related Problems
// 1.Longest Common Substring (√)
// 2.Print LCS
// 3.Shortest Common SuperSequence(√)
// 4.Print SCS(√)
// 5.Min Number of insertion and deletion to convert a-->b(√)
// 6.Longest Repeating Subsequence(√)
// 7.Lenth of longst subsequence of a whhich is a substring in b
// 8.Subsequence Pattern Matching
// 9.Count how many times a appears as subsequence in b
// 10.longest palindrome subsequence(√)
// 11.longest palindromic substring
// 12.Count of palindromic substring
// 13.Min number of deletions to make a string palindrome(√)
// 14.Min number of insertion to make a string palindrome(√)


// Problem Statement: Given two strings, find the length of their longest common subsequence (LCS).

// ========================================Memoization(Bottom-Up)==================================
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int lc_subsequence(string str1, string str2, int n, int m){
    if(n==0 || m==0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(str1[n-1] == str2[m-1]){
        return dp[n][m]= 1+lc_subsequence(str1,str2,n-1,m-1);
    }
    else{
        return dp[n][m] =  max(lc_subsequence(str1,str2,n,m-1),lc_subsequence(str1,str2,n-1,m));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string string1,string2;
    cin >> string1 >> string2;
    int n = string1.size();
    int m = string2.size();

    memset(dp,-1,sizeof(dp));
    cout << lc_subsequence(string1,string2,n,m);

    return 0;
}



// ======================================TOP-Down====================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str1,str2;
    cin >> str1>>str2;
    int n = str1.size();
    int m = str2.size();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    cout << dp[n][m]<<endl;

    return 0;
}
