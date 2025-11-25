// Minimum number of deletions and insertions to transform one string into another
// Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
// Example:
// Input : str1 = "geeksforgeeks", str2 = "geeks"
// Output : Minimum Deletion = 8
//          Minimum Insertion = 0 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin >> s1>>s2;

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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int common =  dp[n][m];

    int deletion = n-common;
    int insertion = m-common;

    cout <<"Deletion: "<< deletion <<endl;
    cout <<"Insertion: " <<insertion<<endl;

    return 0;
}
