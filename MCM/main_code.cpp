// 1.MCM
// 2.Printing MCM
// 3.Evaluate Expression to True Boolean Parenthesization Recursive
// 4.Min/Max value of an Expression
// 5.Palindrome Partitioning
// 6.Scramble String
// 7.Egg Dropping Problem

// #include <bits/stdc++.h>
// using namespace std;

// //MCM template
// int solve(int arr[],int i, int j){

//     //this condition will change based on Problem statement
//     if(i>j) return 0;

//     //this k loop will be change based on Problem Statement
//     for(int k = i;k<j;k++){
//         //this "+" will be anything based on Problem Statement
//         int tempAns = solve(arr,i,k) + solve(k+1,j);

//         //this Function Can be anything to find the ans
//         ans = anyFunction(tempAns);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }

// Problem Statement: https://www.geeksforgeeks.org/dsa/matrix-chain-multiplication-dp-8/
// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to  perform the multiplications, but merely to decide in which order to perform the multiplications.

#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

        if(tempAns < ans){
            ans = tempAns;
        }
    }

    return dp[i][j] =  ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];
    memset(dp,-1,sizeof(dp));

    cout << solve(arr,1,n-1);

    return 0;
}
